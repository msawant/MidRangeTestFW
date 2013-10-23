#include "edma.h"
#include <drivers/psc.h>
#include <debug/knxdebug.h>
#include <ti/pspiom/cslr/cslr.h>
#include <ti/pspiom/cslr/soc_OMAPL138.h>
#include <ti/pspiom/cslr/cslr_edma3cc.h>
#include <OsServices/OSIntLock.h>

// Definitions for each project using the EDMA
#if defined (OMAP_DSP)
	#define EDMA_CPU_REGION (1)
	#define EDMA_QDMA_CHANNEL_START (4)
	#define EDMA_QDMA_PARAM_START (96)
	#define EDMA_TCC_START (16)
	#define EDMA_MAIN_PARAM_START (100)

#elif defined (OMAP_ARM) || defined (MR_KBL)
	#define EDMA_CPU_REGION (0)
	#define EDMA_QDMA_CHANNEL_START (0)
	#define EDMA_QDMA_PARAM_START (64)
	#define EDMA_TCC_START (0)
	#define EDMA_MAIN_PARAM_START (68)
#endif
#define EDMA_QDMA_TOTAL_CHANNELS (4)
#define EDMA_TOTAL_TCCS (16)
#define EDMA_TOTAL_MAIN_PARAM (32 - EDMA_QDMA_TOTAL_CHANNELS)
#define EDMA_REGION_DRAE_REGS(edmaCCRegs) (edmaCCRegs->DRA[EDMA_CPU_REGION])
#define EDMA_REGION_SHADOW_REGS(edmaCCRegs) (edmaCCRegs->SHADOW[EDMA_CPU_REGION])

// Generic definitions for use within EDMA driver
#define EDMA_CONFIGS_PER_DMAQNUMREG	(8)
#define EDMA_DMAQNUM_TOTAL_BITS_PER_CONFIG (4)
#define EDMA_DMAQNUM_USED_BITS_PER_CONFIG (1)

// Underlying structure for the EDMA Install Handle
typedef struct EDMAInstallStruct
{
	uint8 isInstalled;
	uint8 isEnabled;
}EDMAInstall;
EDMAInstall EDMAEvents[EDMA_TOTAL_EVENT_IDS];

// Underlying structure for all available TCCs
typedef struct EDMATCCInstallStruct
{
	uint8 isInstalled;
	EDMAEVENTID installedID;
	EDMA_CallbackFn callbackFN;
	uint32 callbackArg;
}EDMATCCInstall;
EDMATCCInstall EDMA_CC0_TCCs[EDMA_TOTAL_TCCS];
EDMATCCInstall EDMA_CC1_TCCs[EDMA_TOTAL_TCCS];

// Underlying structure for all available PARAM
typedef struct EDMAPARAMInstallStruct
{
	uint8 isInstalled;
	EDMAEVENTID installedID;
	int8 associatedTCC;
}EDMAPARAMInstall;
EDMAPARAMInstall EDMA_CC0_PARAMs[EDMA_TOTAL_MAIN_PARAM];
EDMAPARAMInstall EDMA_CC1_PARAMs[EDMA_TOTAL_MAIN_PARAM];

// Structure used to parse through an input paramset linked list
// and keep track of the mapping between input paramsets and PARAM
// indexes within the driver.
typedef struct EDMAInputToIndexStruct
{
	EDMATransferParamset* pParamSet;
	uint8 paramIndex;
}EDMAInputToIndex;

// Define for the null link address
#define EDMA_NULL_LINK_ADDRESS (0xFFFF)

//  Local method to find/allocate an available TCC
int8 EMDA_GetAvailableTCC(EDMATCCInstall* tccInstallArray, EDMAEVENTID eventID);
#define EDMA_TCC_UNAVAILABLE (-1)
//  Local method to find/allocate an available PARAM
int8 EMDA_GetAvailablePARAM(EDMAPARAMInstall* paramInstallArray, EDMAEVENTID eventID);
#define EDMA_PARAM_UNAVAILABLE (-1)
// Local method to translate the param index to an actual PARAM register overlay
volatile CSL_Edma3ccParamSetRegs* EDMA_TranslatePARAM(CSL_Edma3ccRegsOvly edmaRegs, uint8 paramIndex);
// Local method to translate the tcc array index to the actual TCC used within the edma cc
uint8 EDMA_TranslateTCC(uint8 tccIndex);
 
// Local variable to hold the SPI1 TX TCC. This is used to quickly vector to the SPI TX ISR.
// This ISR is the basis for the servo loop control and therefore the ISR latency is extremely important
uint32 sSPI1TCCMask = 0; 
uint8 sSPI1TCCIndex = 0;

void EDMA_Init()
{
	uint8 clearCounter;
	
	DBG_Log(DRIVER_DEBUG_ID, VERB_LEVEL2, "EDMA Driver Init!");
	// Clear the region access
	EDMA_REGION_DRAE_REGS(((CSL_Edma3ccRegsOvly)(CSL_EDMA30CC_0_REGS))).DRAE = 0;
	EDMA_REGION_DRAE_REGS(((CSL_Edma3ccRegsOvly)(CSL_EDMA31CC_0_REGS))).DRAE = 0;
	//Clear the event installation array
	for (clearCounter = 0; clearCounter < EDMA_TOTAL_EVENT_IDS; clearCounter++)
	{
		uint32 intKey = OS_IntLock();
		EDMAEvents[clearCounter].isInstalled = FALSE;
		EDMAEvents[clearCounter].isEnabled = FALSE;
		OS_IntRestore(intKey);
	}
	// Clear the TCC installation arrays
	for (clearCounter = 0; clearCounter < EDMA_TOTAL_TCCS; clearCounter++)
	{
		uint32 intKey = OS_IntLock();
	 	EDMA_CC0_TCCs[clearCounter].isInstalled = FALSE;
	 	EDMA_CC1_TCCs[clearCounter].isInstalled = FALSE;
	 	((CSL_Edma3ccRegsOvly)(CSL_EDMA30CC_0_REGS))->IECR = (0x1 << EDMA_TranslateTCC(clearCounter));
	 	((CSL_Edma3ccRegsOvly)(CSL_EDMA31CC_0_REGS))->IECR = (0x1 << EDMA_TranslateTCC(clearCounter));
	 	OS_IntRestore(intKey);
	}
	// Clear the paramset arrays
	for (clearCounter = 0; clearCounter < EDMA_TOTAL_MAIN_PARAM; clearCounter++)
	{
		uint32 intKey = OS_IntLock();
	 	EDMA_CC0_PARAMs[clearCounter].isInstalled = FALSE;
	 	EDMA_CC1_PARAMs[clearCounter].isInstalled = FALSE;
	 	OS_IntRestore(intKey);
	}
	// Clear the high priority SPI1 TCC
	sSPI1TCCMask = 0;
	sSPI1TCCIndex = 0;
	
	// Enable clocking to the EDMA channel controllers and transfer controllers
	PSC_EnablePeripheral(EDMA0_CC0);
	PSC_EnablePeripheral(EDMA0_TC0);
	PSC_EnablePeripheral(EDMA1_CC0);
	PSC_EnablePeripheral(EDMA1_TC0);
}

uint8 EDMA_InstallEventList(EDMAEVENTID eventID, EDMAQUEUEID queueID, EDMATransferParamset* listHead)
{
	// Assume failure prove otherwise
	uint8 returnVal = FALSE;
	
	CSL_Edma3ccRegsOvly edmaRegs = (eventID <= EDMA_CC0_LASTEVENT) ?
		(CSL_Edma3ccRegsOvly)CSL_EDMA30CC_0_REGS : (CSL_Edma3ccRegsOvly)CSL_EDMA31CC_0_REGS;
	uint32 ccEventIDNum = (eventID <= EDMA_CC0_LASTEVENT) ?
		(uint32)eventID : (uint32)eventID - (uint32)EDMA_CC1_FIRST_EVENT;
	
	uint32 intKey = OS_IntLock();
	// Check to ensure that this event isn't already installed
	if (EDMAEvents[eventID].isEnabled)
	{
		DBG_LogUint32(DRIVER_DEBUG_ID, VERB_LEVEL1, "EDMA Event %d Already Installed!", (uint32)eventID);
		OS_IntRestore(intKey);
		return FALSE;
	}
	else
	{
		// Check to see somehow this event is already enabled by something else (could be another core or 
		// potentially this core prior to a reboot)
		if (edmaRegs->EER & (0x00000001 << ccEventIDNum))
		{
			DBG_LogUint32(DRIVER_DEBUG_ID, VERB_LEVEL1, "EDMA Event %d Already Enabled!", (uint32)eventID);
		}
		// We are safe to install the event so immediately mark the event as used for reentrency
		EDMAEvents[eventID].isInstalled = TRUE;
		EDMAEvents[eventID].isEnabled = FALSE;
	}
	OS_IntRestore(intKey);
	
	// Set the event to be mapped to the local region via the DRAE registers
	EDMA_REGION_DRAE_REGS(edmaRegs).DRAE |= (0x00000001 << ccEventIDNum);
	EDMA_DisableEvent(eventID);
	// Set the priority for the user selected event
	{
		volatile uint8 DMAQNumReg = ccEventIDNum/EDMA_CONFIGS_PER_DMAQNUMREG;
		volatile uint8 configLsbWithinReg = (ccEventIDNum % (EDMA_CONFIGS_PER_DMAQNUMREG)) * EDMA_DMAQNUM_TOTAL_BITS_PER_CONFIG;
		CSL_FINSR(edmaRegs->DMAQNUM[DMAQNumReg], configLsbWithinReg + EDMA_DMAQNUM_USED_BITS_PER_CONFIG, configLsbWithinReg, (uint8)queueID);
	}
	
	// Now that the Event configuration stuff is complete we can now deal with the paramset list
	{
		EDMAInputToIndex paramIndexTable[EDMA_TOTAL_MAIN_PARAM];
		uint8 totalParams = 0;
		uint8 paramsetCounter = 0;
		EDMATransferParamset* currentParamset = listHead;
		EDMAPARAMInstall* paramArray = (eventID <= EDMA_CC0_LASTEVENT) ? EDMA_CC0_PARAMs : EDMA_CC1_PARAMs;
		EDMATCCInstall* tccArray = (eventID <= EDMA_CC0_LASTEVENT) ? EDMA_CC0_TCCs : EDMA_CC1_TCCs;
		volatile uint32* lastParamSetLinkReg = NULL;
		
		for (; paramsetCounter < EDMA_TOTAL_MAIN_PARAM; paramsetCounter++)
		{
			// Variable for holding an index into the array used to manage the param
			int8 paramIndex;
			// Variable for holding an index into the array used to manage the tcc
			int8 tccIndex;
			// Variable which determines whether or not this paramset will need a tcc
			uint8 tccIsNeeded = (currentParamset->callbackFN != NULL) || 
				(currentParamset->optionalFlags & EDMA_Flag_Completion_Check_No_Callback);
			// Variable for the current PARAM (in memory)
			volatile CSL_Edma3ccParamSetRegs* pParam;
			
			// Find an open param for this user paramset
			paramIndex = EMDA_GetAvailablePARAM(paramArray, eventID);
			// Store the paramIndex in the paramset itself
			currentParamset->returnParamHandle = (uint8)paramIndex;		
			if (paramIndex == EDMA_PARAM_UNAVAILABLE)
			{
				// No PARAM available major issue!
				DBG_Log(DRIVER_DEBUG_ID, VERB_LEVEL1, "EDMA PARAM Resources Exhuasted!");
				break;
			}
			// Save the param set off into the index table
			paramIndexTable[totalParams].pParamSet = currentParamset;
			paramIndexTable[totalParams++].paramIndex = paramIndex;
			// Find an open TCC if this paramset needs it.
			if (tccIsNeeded)
			{
				// Find an open param for this user paramset
				tccIndex = EMDA_GetAvailableTCC(tccArray, eventID);
				if (tccIndex != EDMA_TCC_UNAVAILABLE) 
				{
					// Store the associated tcc index in the param install array, so it can be used
					// later in the case of someone asyncronously checking for a completed paramset
					paramArray[paramIndex].associatedTCC = tccIndex;
					// Store the callback function and arguments
					tccArray[tccIndex].callbackFN = currentParamset->callbackFN;
					tccArray[tccIndex].callbackArg = currentParamset->callbackArg;
					// Set the event to be mapped to the local region via the DRAE registers assuming callbacks are desired
					if (currentParamset->callbackFN != NULL)
					{
						EDMA_REGION_DRAE_REGS(edmaRegs).DRAE |= (0x00000001 << EDMA_TranslateTCC(tccIndex));
					}
					// If we just obtained a TCC for the high priority SPI1 ISR. Then store that
					if (eventID == EDMA_SPI1_TRANSMIT)
					{
						sSPI1TCCMask = (0x00000001 << EDMA_TranslateTCC(tccIndex));
						sSPI1TCCIndex = tccIndex;
					}
				}
				else
				{
					// No TCC available major issue!
					DBG_Log(DRIVER_DEBUG_ID, VERB_LEVEL1, "EDMA TCC Resources Exhuasted!");
					break;
				}
			}
			else
			{
				// No TCC is needed so set the unavailable flag just in case someone attempts to
				// get the status of completion status of a paramset that they did not correctly configure
				// to use TCCS (via callback or EDMA_Flag_Completion_Check_No_Callback flag)
				paramArray[paramIndex].associatedTCC = EDMA_TCC_UNAVAILABLE;
			}
			// Get a pointer to the true PARAM in memory based on the index.
			pParam = EDMA_TranslatePARAM(edmaRegs, paramIndex);
			if (pParam == NULL) break;
			// Now set this PARAM in the link field of another (if it is waiting)
			if (lastParamSetLinkReg != NULL)
			{
				//Note: Purposely cast to a 16-bit value. Link field is a 16-bit memory offset
				*lastParamSetLinkReg |= ((uint32)pParam & 0xFFFF);
			}
			pParam->OPT = 0;
			// Set syncronization type. Note A set by default because whole field is zeroed above
			if (currentParamset->optionalFlags & EDMA_Flag_AB_Syncronized)
			{
				CSL_FINST(pParam->OPT, EDMA3CC_OPT_SYNCDIM, ABSYNC);
			}
			if (tccIsNeeded)
			{ 
				// Set the TCC being used within the opt field.
				pParam->OPT |= ( (EDMA_TranslateTCC(tccIndex) << CSL_EDMA3CC_OPT_TCC_SHIFT) & CSL_EDMA3CC_OPT_TCC_MASK ); 
				// Set the tcc mode. Note normal completion set by default because whole field is zeroed above
				if (currentParamset->optionalFlags & EDMA_Flag_Early_Completion)
				{
					CSL_FINST(pParam->OPT, EDMA3CC_OPT_TCCMOD, EARLY);
				}
				// Set the interrupt type. Always set interrupt on complete.
				CSL_FINST(pParam->OPT, EDMA3CC_OPT_TCINTEN, ENABLE);
				// Set the interrmediate interrupts as well if the user desired
				if (currentParamset->optionalFlags & EDMA_Flag_Early_Completion)
				{
					CSL_FINST(pParam->OPT, EDMA3CC_OPT_ITCINTEN, ENABLE);
				}
				// Be sure to enable the ISRs for the given TCC if callbacks are desired
				if (currentParamset->callbackFN != NULL)
				{
					EDMA_REGION_SHADOW_REGS(edmaRegs).IESR = (0x00000001 << EDMA_TranslateTCC(tccIndex));
				}
				
			}
			// Set the source address
			pParam->SRC = currentParamset->srcAddress;
			// Set the A and B count register
			pParam->A_B_CNT = 	((uint32)(currentParamset->BCNT_numberOfEventsPerFrame) << CSL_EDMA3CC_A_B_CNT_BCNT_SHIFT) |
								((uint32)(currentParamset->ACNT_transferSizePerEvent));
			// Set the destination address
			pParam->DST = currentParamset->dstAddress;
			// Set the source and destination b index register
			pParam->SRC_DST_BIDX = 	((uint32)((uint16)(currentParamset->DSTBIDX_dstIndexAfterEvent)) 
										<< CSL_EDMA3CC_SRC_DST_BIDX_DSTBIDX_SHIFT) |
									((uint16)(currentParamset->SRCBIDX_srcIndexAfterEvent));
			// Set the source and destination c index register
			pParam->SRC_DST_CIDX = 	((uint32)((uint16)(currentParamset->DSTCIDX_dstIndexAfterFrame)) 
										<< CSL_EDMA3CC_SRC_DST_CIDX_DSTCIDX_SHIFT) |
									((uint16)(currentParamset->SRCCIDX_srcIndexAfterFrame));
			// Set the CCNT register
			pParam->CCNT = (uint32)(currentParamset->CCNT_totalFramesForCompletion);
			// Set the B count reload and link registers
			// We are now ready to evaluate the next paramset field. There are 3 potential cases:
			// 1) NULL link. The user is specifying no link to be used. Fill in null link and we are complete
			// 2) New Paramset*. The user is specifiing another paramset which we have not yet encountered.
			//		Therefore because it is not yet defined we will have to store the location of this register
			//		so that once the new PARAM is defined it can be linked to this one.
			// 3) Existing Paramset*. The user is specifying for this paramset to link to a previously defined
			// 		paramset. In this case we look up the address of that PARAM link it and we are complete.
			pParam->LINK_BCNTRLD = 	((uint32)(currentParamset->BCNTRLD_aSyncBcntReloadAfterFrame) 
									<< CSL_EDMA3CC_LINK_BCNTRLD_BCNTRLD_SHIFT);
			if (currentParamset->linkParamSet == NULL)
			{
				pParam->LINK_BCNTRLD |= EDMA_NULL_LINK_ADDRESS;
				// Null link so we are done!
				returnVal = TRUE;
				break;
			}
			else
			{
				// Look for this paramset, to see if it is previously defined 
				uint8 previouslyDefined = FALSE;
				uint8 searchCounter = 0;
				for (; searchCounter < totalParams; searchCounter++)
				{
					if (	paramIndexTable[searchCounter].pParamSet ==
							currentParamset->linkParamSet )
					{
						// We found a previously defined set. So link this paramset to it and set found flag
						//Note: Purposely cast to a 16-bit value. Link field is a 16-bit memory offset
						pParam->LINK_BCNTRLD |= 
							( (uint32)EDMA_TranslatePARAM(edmaRegs, paramIndexTable[searchCounter].paramIndex) & 0xFFFF );
						previouslyDefined = TRUE;
						break;
					}
				}
				// Check to see if this was a new paramset or not
				if (previouslyDefined)
				{
					// Paramset was previously defined so we are done!
					returnVal = TRUE;
					break;
				}
				else
				{
					// New paramset, so save location to store this link
					lastParamSetLinkReg = &(pParam->LINK_BCNTRLD);
				}	// End check for if we found the paramset previously defined
			}		// End check for next paramset field
			
			// Increment through the list to the next paramset
			currentParamset = currentParamset->linkParamSet;
			
		}			// End the loop for all incoming paramsets
		// If we successfully created the paramset list in memory then we copy the first PARAM into the
		// actual DMA event PARAM.
		if (returnVal)
		{
			edmaRegs->PARAMSET[ccEventIDNum] = *(EDMA_TranslatePARAM(edmaRegs, paramIndexTable[0].paramIndex));
		}
	}
	// If we encountered an error so we will uninstall the event to relinquish all of the resources
	if (returnVal == FALSE)
	{
		EDMA_UninstallEventList(eventID);
	}
	
	return returnVal;
}

uint8 EDMA_ReSyncEvent(EDMAEVENTID eventID, uint8 paramHandle)
{
	CSL_Edma3ccRegsOvly edmaRegs = (eventID <= EDMA_CC0_LASTEVENT) ?
		(CSL_Edma3ccRegsOvly)CSL_EDMA30CC_0_REGS : (CSL_Edma3ccRegsOvly)CSL_EDMA31CC_0_REGS;
	uint32 ccEventIDNum = (eventID <= EDMA_CC0_LASTEVENT) ?
		(uint32)eventID : (uint32)eventID - (uint32)EDMA_CC1_FIRST_EVENT;
	EDMAPARAMInstall* paramArray = (eventID <= EDMA_CC0_LASTEVENT) ? EDMA_CC0_PARAMs : EDMA_CC1_PARAMs;
		
	if (paramHandle < EDMA_TOTAL_MAIN_PARAM)
	{
		if ( (paramArray[paramHandle].isInstalled) && (paramArray[paramHandle].installedID == eventID) )
		{
			// The input is valid so copy the given the handle to the main event paramset to resync the event
			edmaRegs->PARAMSET[ccEventIDNum] = edmaRegs->PARAMSET[EDMA_MAIN_PARAM_START + paramHandle];
			return TRUE;
		}
	}
	
	// If we get here something was awry. Bad input value or a confused user.
	DBG_LogUint32(DRIVER_DEBUG_ID, VERB_LEVEL1, "EDMA failure to Resync event %d", (uint32)eventID);
	return FALSE;
}

uint8 EDMA_UninstallEventList(EDMAEVENTID eventID)
{
	uint8 returnVal = TRUE;
	CSL_Edma3ccRegsOvly edmaRegs = (eventID <= EDMA_CC0_LASTEVENT) ?
		(CSL_Edma3ccRegsOvly)CSL_EDMA30CC_0_REGS : (CSL_Edma3ccRegsOvly)CSL_EDMA31CC_0_REGS;
	uint32 ccEventIDNum = (eventID <= EDMA_CC0_LASTEVENT) ?
		(uint32)eventID : (uint32)eventID - (uint32)EDMA_CC1_FIRST_EVENT;
	EDMAPARAMInstall* paramArray = (eventID <= EDMA_CC0_LASTEVENT) ? EDMA_CC0_PARAMs : EDMA_CC1_PARAMs;
	EDMATCCInstall* tccArray = (eventID <= EDMA_CC0_LASTEVENT) ? EDMA_CC0_TCCs : EDMA_CC1_TCCs;
	uint8 searchCounter;
	
	uint32 intKey = OS_IntLock();
	EDMAEvents[eventID].isInstalled = FALSE;
	EDMAEvents[eventID].isEnabled = FALSE;
	OS_IntRestore(intKey);
	// Clear DRAE for the main event dma channel
	EDMA_REGION_DRAE_REGS(edmaRegs).DRAE &= ~(0x00000001 << ccEventIDNum);
	
	// Clear out any TCCs associated with this event
	
	
	// Loop through the TCC install array and clear out entry entries associated with this eventID
	for (searchCounter = 0; searchCounter < EDMA_TOTAL_TCCS ; searchCounter++)
	{
		intKey = OS_IntLock();
		if (	(tccArray[searchCounter].isInstalled) &&
				(tccArray[searchCounter].installedID == eventID) )
		{
			tccArray[searchCounter].isInstalled = FALSE;
			// Clear DRAE for the tcc
			EDMA_REGION_DRAE_REGS(edmaRegs).DRAE &= ~(0x00000001 << (searchCounter + EDMA_TCC_START));
		}
		OS_IntRestore(intKey);
	}
	// Loop through the PARAM install array looking and clear out entry entries associated with this eventID
	for (searchCounter = 0; searchCounter < EDMA_TOTAL_MAIN_PARAM ; searchCounter++)
	{
		intKey = OS_IntLock();
		if (	(paramArray[searchCounter].isInstalled) &&
				(paramArray[searchCounter].installedID == eventID) )
		{
			paramArray[searchCounter].isInstalled = FALSE;
		}
		OS_IntRestore(intKey);
	}
	// If we uninstalled the high priority SPI1 RX event, then be sure to clear the high speed bypass variables.
	if (eventID == EDMA_SPI1_TRANSMIT)
	{
		sSPI1TCCMask = 0;
		sSPI1TCCIndex = 0;
	}
	return returnVal;
}

uint8 EDMA_EnableEvent(EDMAEVENTID eventID)
{
	uint8 returnVal = FALSE;
	CSL_Edma3ccRegsOvly edmaRegs = (eventID <= EDMA_CC0_LASTEVENT) ?
		(CSL_Edma3ccRegsOvly)CSL_EDMA30CC_0_REGS : (CSL_Edma3ccRegsOvly)CSL_EDMA31CC_0_REGS;
	uint32 ccEventIDNum = (eventID <= EDMA_CC0_LASTEVENT) ?
		(uint32)eventID : (uint32)eventID - (uint32)EDMA_CC1_FIRST_EVENT;
		
	// Verify that the event in question is in fact installed
	uint32 intKey = OS_IntLock();
	if (EDMAEvents[eventID].isInstalled)
	{
		EDMAEvents[eventID].isEnabled = TRUE;
		EDMA_REGION_SHADOW_REGS(edmaRegs).EESR = (0x00000001 << ccEventIDNum);
		returnVal = TRUE;
	}
	else
	{
		DBG_LogUint32(DRIVER_DEBUG_ID, VERB_LEVEL1, "EDMA attempting to enable event %d that is not installed!", (uint32)eventID);
	}
	OS_IntRestore(intKey); 
	
	return returnVal;
}

uint8 EDMA_DisableEvent(EDMAEVENTID eventID)
{
	uint8 returnVal = FALSE;
	CSL_Edma3ccRegsOvly edmaRegs = (eventID <= EDMA_CC0_LASTEVENT) ?
		(CSL_Edma3ccRegsOvly)CSL_EDMA30CC_0_REGS : (CSL_Edma3ccRegsOvly)CSL_EDMA31CC_0_REGS;
	uint32 ccEventIDNum = (eventID <= EDMA_CC0_LASTEVENT) ?
		(uint32)eventID : (uint32)eventID - (uint32)EDMA_CC1_FIRST_EVENT;
		
	// Verify that the event in question is in fact installed
	uint32 intKey = OS_IntLock(); 
	if (EDMAEvents[eventID].isInstalled)
	{
		EDMAEvents[eventID].isEnabled = FALSE;
		EDMA_REGION_SHADOW_REGS(edmaRegs).EECR = (0x00000001 << ccEventIDNum);
		returnVal = TRUE;
	}
	else
	{
		DBG_LogUint32(DRIVER_DEBUG_ID, VERB_LEVEL1, "EDMA attempting to disable event %d that is not installed!", (uint32)eventID);
	}
	OS_IntRestore(intKey); 
	
	return returnVal;
}

// Verify completion of a specific param handle from a previously installed paramset list
uint8 EDMA_IsParamComplete(EDMAEVENTID eventID, uint8 paramHandle)
{
	CSL_Edma3ccRegsOvly edmaRegs = (eventID <= EDMA_CC0_LASTEVENT) ?
		(CSL_Edma3ccRegsOvly)CSL_EDMA30CC_0_REGS : (CSL_Edma3ccRegsOvly)CSL_EDMA31CC_0_REGS;
	EDMAPARAMInstall* paramArray = (eventID <= EDMA_CC0_LASTEVENT) ? EDMA_CC0_PARAMs : EDMA_CC1_PARAMs;
		
	if (paramHandle < EDMA_TOTAL_MAIN_PARAM)
	{
		if ( (paramArray[paramHandle].isInstalled) && (paramArray[paramHandle].installedID == eventID) && (paramArray[paramHandle].associatedTCC != EDMA_TCC_UNAVAILABLE))
		{
			// This is a at least we have a valid handle that uses a TCC and it is associated with the event ID.
			// Now verify if that event is complete or not. Note because returning a uint8 we can not simply
			// return the expression (which would yeild a 32-bit return value implicitly cast to uint8) but rather
			// use a ternary and then return the defined TRUE or FALSE variable
			return ( edmaRegs->IPR & (0x1 << (paramArray[paramHandle].associatedTCC + EDMA_TCC_START)) ) ? TRUE : FALSE;
		}
	}
	
	// If we get here something was awry. Bad input value or a confused user.
	DBG_LogUint32(DRIVER_DEBUG_ID, VERB_LEVEL1, "EDMA param complete check on invalid handle. Event ID: %d", (uint32)eventID);
	return FALSE;
}

// Clear completion status of a specific param handle from a previously installed paramset list
uint8 EDMA_ClearParamComplete(EDMAEVENTID eventID, uint8 paramHandle)
{
	CSL_Edma3ccRegsOvly edmaRegs = (eventID <= EDMA_CC0_LASTEVENT) ?
		(CSL_Edma3ccRegsOvly)CSL_EDMA30CC_0_REGS : (CSL_Edma3ccRegsOvly)CSL_EDMA31CC_0_REGS;
	EDMAPARAMInstall* paramArray = (eventID <= EDMA_CC0_LASTEVENT) ? EDMA_CC0_PARAMs : EDMA_CC1_PARAMs;
		
	if (paramHandle < EDMA_TOTAL_MAIN_PARAM)
	{
		if ( (paramArray[paramHandle].isInstalled) && (paramArray[paramHandle].installedID == eventID) && (paramArray[paramHandle].associatedTCC != EDMA_TCC_UNAVAILABLE))
		{
			// This is a at least we have a valid handle that uses a TCC and it is associated with the event ID.
			// Now verify if that event is complete or not.
			edmaRegs->ICR = (0x1 << (paramArray[paramHandle].associatedTCC + EDMA_TCC_START));
			return TRUE;
		}
	}
	
	// If we get here something was awry. Bad input value or a confused user.
	DBG_LogUint32(DRIVER_DEBUG_ID, VERB_LEVEL1, "EDMA param complete clear on invalid handle. Event ID: %d", (uint32)eventID);
	return FALSE;
}


int8 EMDA_GetAvailableTCC(EDMATCCInstall* tccInstallArray, EDMAEVENTID eventID)
{
	int8 returnVal = EDMA_TCC_UNAVAILABLE;
	uint8 tccSearchCounter = 0;
	
	// Loop through the TCC install array looking for an open location
	for (; tccSearchCounter < EDMA_TOTAL_TCCS ; tccSearchCounter++)
	{
		uint32 intKey = OS_IntLock(); 
		if ( !(tccInstallArray[tccSearchCounter].isInstalled) )
		{
			tccInstallArray[tccSearchCounter].isInstalled = TRUE;
			tccInstallArray[tccSearchCounter].installedID = eventID;
			returnVal = tccSearchCounter;
			OS_IntRestore(intKey);
			break;
		}
		OS_IntRestore(intKey);
	}
	
	return returnVal;
}

int8 EMDA_GetAvailablePARAM(EDMAPARAMInstall* paramInstallArray, EDMAEVENTID eventID)
{
	int8 returnVal = EDMA_PARAM_UNAVAILABLE;
	uint8 paramSearchCounter = 0;
	
	// Loop through the TCC install array looking for an open location
	for (; paramSearchCounter < EDMA_TOTAL_MAIN_PARAM ; paramSearchCounter++)
	{
		uint32 intKey = OS_IntLock(); 
		if ( !(paramInstallArray[paramSearchCounter].isInstalled) )
		{
			paramInstallArray[paramSearchCounter].isInstalled = TRUE;
			paramInstallArray[paramSearchCounter].installedID = eventID;
			returnVal = paramSearchCounter;
			OS_IntRestore(intKey);
			break;
		}
		OS_IntRestore(intKey);
	}
	
	return returnVal;
}

volatile CSL_Edma3ccParamSetRegs* EDMA_TranslatePARAM(CSL_Edma3ccRegsOvly edmaRegs, uint8 paramIndex)
{
	// Sanity check the input
	if (paramIndex >= EDMA_TOTAL_MAIN_PARAM)
	{
		DBG_Log(DRIVER_DEBUG_ID, VERB_LEVEL1, "EDMA Invalid PARAM index detected!");
		return NULL;
	}
	return &(edmaRegs->PARAMSET[EDMA_MAIN_PARAM_START + paramIndex]);
}

uint8 EDMA_TranslateTCC(uint8 tccIndex)
{
	// Sanity check the input
	if (tccIndex >= EDMA_TOTAL_TCCS)
	{
		DBG_Log(DRIVER_DEBUG_ID, VERB_LEVEL1, "EDMA Invalid TCC index detected!");
		return 0; //return NULL; Integrity does not like NULL being returned for uint8
	}
	return (tccIndex+EDMA_TCC_START);
}

void EMDA_CC0ISRHandler(void)
{
	uint32 IPRVal;
	
	// Check for the low latency SPI RX event first 
//	if (EDMA_REGION_SHADOW_REGS( ((CSL_Edma3ccRegsOvly)CSL_EDMA30CC_0_REGS) ).IPR & sSPI1TCCMask)
//	{
//		EDMA_CC0_TCCs[sSPI1TCCIndex].callbackFN(EDMA_CC0_TCCs[sSPI1TCCIndex].callbackArg);
//		EDMA_REGION_SHADOW_REGS( ((CSL_Edma3ccRegsOvly)CSL_EDMA30CC_0_REGS) ).ICR = sSPI1TCCMask;
//	}
	
	IPRVal =	(EDMA_REGION_SHADOW_REGS( ((CSL_Edma3ccRegsOvly)CSL_EDMA30CC_0_REGS) ).IPR) &
				(EDMA_REGION_SHADOW_REGS( ((CSL_Edma3ccRegsOvly)CSL_EDMA30CC_0_REGS) ).IER);

	// Loop until all IPRs are clear
	while ( IPRVal )
	{
		uint32 IPRTccBit = 0;
		
		// Now shift the IPR value down so that everything is referenced to 0
		IPRVal = IPRVal >> EDMA_TCC_START;
		
		// Loop through all bits set in the IPR and call the corresponding callback
		while (IPRVal)
		{
			// Check to see if the current TCC bit is set
			if (IPRVal & 0x1)
			{
				// Clear the bit first. This ensures that in the case another event comes in for this, while processing it
				// the flag will get latched again in the IPR.
				EDMA_REGION_SHADOW_REGS( ((CSL_Edma3ccRegsOvly)CSL_EDMA30CC_0_REGS) ).ICR = ( (1 << IPRTccBit) << EDMA_TCC_START );
				// Verify that this event is installed and can be used
				if (	(EDMA_CC0_TCCs[IPRTccBit].isInstalled) &&
						(EDMA_CC0_TCCs[IPRTccBit].callbackFN != NULL)	)
				{
					EDMA_CC0_TCCs[IPRTccBit].callbackFN(EDMA_CC0_TCCs[IPRTccBit].callbackArg);
				}
				else
				{
					DBG_LogUint32(DRIVER_DEBUG_ID, VERB_LEVEL1, "EDMA invalid TCC detected in IPR %d!", (uint32)IPRTccBit);
				}
			}
			// Now check the next bit
			IPRVal = IPRVal >> 1;
			IPRTccBit++;
		}
		// Reload the IPR Value just to make sure no new events posted while we were processing these
		IPRVal =	(EDMA_REGION_SHADOW_REGS( ((CSL_Edma3ccRegsOvly)CSL_EDMA30CC_0_REGS) ).IPR) &
					(EDMA_REGION_SHADOW_REGS( ((CSL_Edma3ccRegsOvly)CSL_EDMA30CC_0_REGS) ).IER);
	}
}

void EMDA_CC1ISRHandler(void)
{
	uint32 IPRVal =	(EDMA_REGION_SHADOW_REGS( ((CSL_Edma3ccRegsOvly)CSL_EDMA31CC_0_REGS) ).IPR) &
					(EDMA_REGION_SHADOW_REGS( ((CSL_Edma3ccRegsOvly)CSL_EDMA31CC_0_REGS) ).IER);
				
	// Loop until all IPRs are clear
	while ( IPRVal )
	{
		uint32 IPRTccBit = 0;
		
		// Now shift the IPR value down so that everything is referenced to 0
		IPRVal = IPRVal >> EDMA_TCC_START;
		
		// Loop through all bits set in the IPR and call the corresponding callback
		while (IPRVal)
		{
			// Check to see if the current TCC bit is set
			if (IPRVal & 0x1)
			{
				// Clear the bit first. This ensures that in the case another event comes in for this, while processing it
				// the flag will get latched again in the IPR.
				EDMA_REGION_SHADOW_REGS( ((CSL_Edma3ccRegsOvly)CSL_EDMA31CC_0_REGS) ).ICR = ( (1 << IPRTccBit) << EDMA_TCC_START );
				// Verify that this event is installed and can be used
				if (	(EDMA_CC1_TCCs[IPRTccBit].isInstalled) &&
						(EDMA_CC1_TCCs[IPRTccBit].callbackFN != NULL)	)
				{
					EDMA_CC1_TCCs[IPRTccBit].callbackFN(EDMA_CC0_TCCs[IPRTccBit].callbackArg);
				}
				else
				{
					DBG_LogUint32(DRIVER_DEBUG_ID, VERB_LEVEL1, "EDMA invalid TCC detected in IPR %d!", (uint32)IPRTccBit);
				}
			}
			// Now check the next bit
			IPRVal = IPRVal >> 1;
			IPRTccBit++;
		}
		// Reload the IPR Value just to make sure no new events posted while we were processing these
		IPRVal =	(EDMA_REGION_SHADOW_REGS( ((CSL_Edma3ccRegsOvly)CSL_EDMA31CC_0_REGS) ).IPR) &
					(EDMA_REGION_SHADOW_REGS( ((CSL_Edma3ccRegsOvly)CSL_EDMA31CC_0_REGS) ).IER);
	}
}

#ifndef EDMA_H_
#define EDMA_H_

#include <DataTypes.h>

#if defined(OMAP_ARM)

	#include <INTEGRITY.h>
	
	#ifndef TRUE
	    #define TRUE true
	#endif
	
	#ifndef FALSE
	    #define FALSE false
	#endif

#endif

#ifdef __cplusplus
extern "C" {
#endif

// Enumeration of all the peripheral events which can cause an edma transfer.
// NOTE: ORDERING IMPORTANT BASED ON THE EDMA CONTROLLER PERIPHERAL BY TI
typedef enum EDMAEVENTIDENUM
{
	// EDMACC0 Events
	EDMA_CC0_FIRST_EVENT = 0,
	EDMA_MCASP0_RECEIVE = 0,
	EDMA_MCASP0_TRANSMIT = 1,
	EDMA_MCBSP0_RECEIVE = 2,
	EDMA_MCBSP0_TRANSMIT = 3,
	EDMA_MCBSP1_RECEIVE = 4,
	EDMA_MCBSP1_TRANSMIT = 5,
	EDMA_GPIO_BANK0_INTERRUPT = 6,
	EDMA_GPIO_BANK1_INTERRUPT = 7,
	EDMA_UART0_RECEIVE = 8,
	EDMA_UART0_TRANSMIT = 9,
	EDMA_TIMER64P0_EVENTOUT12 = 10,
	EDMA_TIMER64P0_EVENTOUT34 = 11,
	EDMA_UART1_RECEIVE = 12,
	EDMA_UART1_TRANSMIT = 13,
	EDMA_SPI0_RECEIVE = 14,
	EDMA_SPI0_TRANSMIT = 15,
	EDMA_MMCSD0_RECEIVE = 16,
	EMDA_MMCSD0_TRANSMIT = 17,
	EDMA_SPI1_RECEIVE = 18,
	EDMA_SPI1_TRANSMIT = 19,
	EDMA_PRU_EVTOUT6 = 20,
	EDMA_PRU_EVTOUT7 = 21,
	EDMA_GPIO_BANK2_INTERRUPT = 22,
	EDMA_GPIO_BANK3_INTERRUPT = 23,
	EDMA_I2C0_RECEIVE = 24,
	EDMA_I2C0_TRANSMIT = 25,
	EDMA_I2C1_RECEIVE = 26,
	EDMA_I2C1_TRANSMIT = 27,
	EDMA_GPIO_BANK4_INTERRUPT = 28,
	EDMA_GPIO_BANK5_INTERRUPT = 29,
	EDMA_UART2_RECEIVE = 30,
	EDMA_UART2_TRANSMIT = 31,
	EDMA_CC0_LASTEVENT = 31,
	// EDMACC 1 Events
	EDMA_CC1_FIRST_EVENT = 32,
	EDMA_TIMER64P2_COMPAREEVENT0 = 32,
	EDMA_TIMER64P2_COMPAREEVENT1 = 33,
	EDMA_TIMER64P2_COMPAREEVENT2 = 34,
	EDMA_TIMER64P2_COMPAREEVENT3 = 35,
	EDMA_TIMER64P2_COMPAREEVENT4 = 36,
	EDMA_TIMER64P2_COMPAREEVENT5 = 37,
	EDMA_TIMER64P2_COMPAREEVENT6 = 38,
	EDMA_TIMER64P2_COMPAREEVENT7 = 39,
	EDMA_TIMER64P3_COMPAREEVENT0 = 40,
	EDMA_TIMER64P3_COMPAREEVENT1 = 41,
	EDMA_TIMER64P3_COMPAREEVENT2 = 42,
	EDMA_TIMER64P3_COMPAREEVENT3 = 43,
	EDMA_TIMER64P3_COMPAREEVENT4 = 44,
	EDMA_TIMER64P3_COMPAREEVENT5 = 45,
	EDMA_TIMER64P3_COMPAREEVENT6 = 46,
	EDMA_TIMER64P3_COMPAREEVENT7 = 47,
	EDMA_GPIO_BANK6_INTERRUPT = 48,
	EDMA_GPIO_BANK7_INTERRUPT = 49,
	EDMA_GPIO_BANK8_INTERRUPT = 50,
	EDMA_CC1_RESERVED0 = 51,
	EDMA_CC1_RESERVED1 = 52,
	EDMA_CC1_RESERVED2 = 53,
	EDMA_CC1_RESERVED3 = 54,
	EDMA_CC1_RESERVED4 = 55,
	EDMA_TIMER64P2_EVENTOUT12 = 56,
	EDMA_TIMER64P2_EVENTOUT34 = 57,
	EDMA_TIMER64P3_EVENTOUT12 = 58,
	EDMA_TIMER64P3_EVENTOUT34 = 59,
	EDMA_MMCSD0_RECEIVE_ALT = 60,			// Note: This event is also available in cc0, so we will append "ALT" onto this event
	EMDA_MMCSD0_TRANSMIT_ALT = 61,			// Note: This event is also available in cc0, so we will append "ALT" onto this event
	EDMA_CC1_RESERVED5 = 62,
	EDMA_CC1_RESERVED6 = 63,
	EDMA_CC1_LAST_EVENT = 63,
	
	EDMA_TOTAL_EVENT_IDS = 64
} EDMAEVENTID;

// Enumeration for the queue id to use for a specific parameter set.
// ***NOTE EDMA_QUEUE_HIGH_PRIORITY should be used very carefully, only servo control
// based events (such as SPI data transfer to/from piccolo and servo related dma
// transfers to/from KCL should use the high priority queue.***
// *** ALL OTHER TRANSFERS SHOULD USE EDMA_QUEUE_STANDARD ***
// NOTE: ORDERING IMPORTANT BASED ON THE EDMA CONTROLLER PERIPHERAL BY TI
typedef enum EDMAQUEUEIDENUM
{
	EDMA_QUEUE_HIGH_PRIORITY = 0,
	EDMA_QUEUE_STANDARD	= 1
} EDMAQUEUEID;

// Set of flags which can be used in the optionalFlags field of a EDMATransferParamset.
// Designed to be ORed together
// Type of syncronization either A (default) or AB
#define EDMA_Flag_A_Syncronized (0x0)
#define EDMA_Flag_AB_Syncronized (0x1)
// Type of callback/interrupt completion mode either normal (Default) or early
#define EDMA_Flag_Normal_Completion (0x0)
#define EDMA_Flag_Early_Completion (0x2)
// Type of callback/interrupt. Callback on completion (default) or callback on intermediate transfers and completion
#define EDMA_Flag_Transfer_Complete_Callback (0x0)
#define EDMA_Flag_Intermediate_Transfer_Callback (0x4)
// Option to allow asyncronous verification of completion of a specific transfer paramset, but do not interrupt on completion
#define EDMA_Flag_Completion_Check_No_Callback (0x8)

// Declaration of the EDMA Callback function
typedef void (*EDMA_CallbackFn)(uint32);
// Structure for the EDMA Event list. 
typedef struct EDMATransferParamsetStruct
{
	uint32			srcAddress;
	uint32			dstAddress;
	uint16			ACNT_transferSizePerEvent;
	int16			SRCBIDX_srcIndexAfterEvent;
	int16			DSTBIDX_dstIndexAfterEvent;
	uint16			BCNT_numberOfEventsPerFrame;
	uint16			BCNTRLD_aSyncBcntReloadAfterFrame;
	int16			SRCCIDX_srcIndexAfterFrame;
	int16			DSTCIDX_dstIndexAfterFrame;
	uint16			CCNT_totalFramesForCompletion;
	struct EDMATransferParamsetStruct *linkParamSet;
	EDMA_CallbackFn	callbackFN;
	uint32			callbackArg;
	uint8			optionalFlags;
	uint8			returnParamHandle;
} EDMATransferParamset;

//////////////////////////////////////////////////////////////////////////////////
/////////////////////           Public Methods            ////////////////////////
//////////////////////////////////////////////////////////////////////////////////

// Reset/Initialize the EDMA driver
void EDMA_Init();

// Install a peripheral triggered EDMA list.
uint8 EDMA_InstallEventList(EDMAEVENTID eventID, EDMAQUEUEID queueID, EDMATransferParamset* listHead);
// Re-sync a EDMA event given a previously installed param handle from a previously installed paramset list
uint8 EDMA_ReSyncEvent(EDMAEVENTID eventID, uint8 paramHandle);
// Uninstall a peripheral triggered EDMA list.
uint8 EDMA_UninstallEventList(EDMAEVENTID eventID);
// Enable a previously installed edma event
uint8 EDMA_EnableEvent(EDMAEVENTID eventID);
// Disable a previously installed edma event
uint8 EDMA_DisableEvent(EDMAEVENTID eventID);
// Verify completion of a specific param handle from a previously installed paramset list
uint8 EDMA_IsParamComplete(EDMAEVENTID eventID, uint8 paramHandle);
// Clear completion status of a specific param handle from a previously installed paramset list
uint8 EDMA_ClearParamComplete(EDMAEVENTID eventID, uint8 paramHandle);

#ifdef __cplusplus
}
#endif


#endif /*EDMA_H_*/

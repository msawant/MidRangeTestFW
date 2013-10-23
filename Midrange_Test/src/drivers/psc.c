#include "psc.h"
#include <DataTypes.h>
//#include <debug/knxdebug.h>
#include <ti/pspiom/cslr/cslr.h>
#include <ti/pspiom/cslr/soc_OMAPL138.h>
#include <ti/pspiom/cslr/cslr_psc_OMAPL138.h>

typedef enum PSCINSTANCEENUM
{
	PSC0 = 0,
	PSC1 = 1
} PSC_INSTANCE;

typedef enum POWERDOMAINENUM
{
	PD0 = 0,
	PD1 = 1
} POWER_DOMAIN;

typedef struct PERIPHDESCRIPTORSTRUCT
{
	PERIPHERAL_NAME periphID;
	PSC_INSTANCE pscID;
	POWER_DOMAIN pdID;
	uint8 lpscNum;
} PERIPHERAL_DESCRIPTOR;

const PERIPHERAL_DESCRIPTOR periphArray[TOTAL_NUMBER_OF_PSC_CONTROLLED_PERIPHERALS] = 
{	
	{EDMA0_CC0, 	PSC0, 	PD0, 	CSL_PSC_CC0},			// Array Index 0
	{EDMA0_TC0, 	PSC0, 	PD0, 	CSL_PSC_TC0},			// Array Index 1
	{EDMA0_TC1, 	PSC0, 	PD0, 	CSL_PSC_TC1},			// Array Index 2
	{EMIFA, 		PSC0, 	PD0, 	CSL_PSC_EMIFA},			// Array Index 3
	{SPI0, 			PSC0,	PD0, 	CSL_PSC_SPI0},			// Array Index 4
	{MMC_SD0, 		PSC0,	PD0, 	CSL_PSC_MMCSD0},		// Array Index 5
	{ARM_INTC, 		PSC0,	PD0, 	CSL_PSC_AINTC},			// Array Index 6 
	{ARM_RAM_ROM, 	PSC0, 	PD0, 	CSL_PSC_ARM_RAMROM},	// Array Index 7
	{UART0, 		PSC0, 	PD0, 	CSL_PSC_UART0},			// Array Index 8
	{SCR0, 			PSC0,	PD0, 	CSL_PSC_SCR0_SS},		// Array Index 9
	{SCR1, 			PSC0,	PD0, 	CSL_PSC_SCR1_SS},		// Array Index 10
	{SCR2, 			PSC0, 	PD0, 	CSL_PSC_SCR2_SS},		// Array Index 11
	{PRU, 			PSC0, 	PD0, 	CSL_PSC_PRU},			// Array Index 12
	{ARM, 			PSC0, 	PD0, 	CSL_PSC_ARM},			// Array Index 13
	{DSP, 			PSC0, 	PD1, 	CSL_PSC_DSP},			// Array Index 14
	{EDMA1_CC0, 	PSC1, 	PD0, 	CSL_PSC_CC1},			// Array Index 15
	{USB0, 			PSC1, 	PD0, 	CSL_PSC_USB0},			// Array Index 16
	{USB1, 			PSC1, 	PD0, 	CSL_PSC_USB1},			// Array Index 17
	{GPIO, 			PSC1, 	PD0, 	CSL_PSC_GPIO},			// Array Index 18
	{HPI, 			PSC1, 	PD0, 	CSL_PSC_UHPI},			// Array Index 19
	{EMAC, 			PSC1, 	PD0, 	CSL_PSC_EMAC},			// Array Index 20
	{DDR2_MDDR, 	PSC1, 	PD0, 	CSL_PSC_DDR2_MDDR},		// Array Index 21
	{MCASP0, 		PSC1, 	PD0, 	CSL_PSC_MCASP0},		// Array Index 22
	{SATA, 			PSC1, 	PD0, 	CSL_PSC_SATA},			// Array Index 23
	{VPIF, 			PSC1, 	PD0, 	CSL_PSC_VPIF},			// Array Index 24
	{SPI1, 			PSC1, 	PD0, 	CSL_PSC_SPI1},			// Array Index 25
	{IIC1, 			PSC1, 	PD0, 	CSL_PSC_I2C1},			// Array Index 26
	{UART1, 		PSC1, 	PD0, 	CSL_PSC_UART1},			// Array Index 27
	{UART2,	 		PSC1, 	PD0, 	CSL_PSC_UART2},			// Array Index 28
	{MCBSP0, 		PSC1, 	PD0, 	CSL_PSC_MCBSP0},		// Array Index 29
	{MCBSP1, 		PSC1, 	PD0, 	CSL_PSC_MCBSP1},		// Array Index 30
	{LCDC, 			PSC1, 	PD0, 	CSL_PSC_LCDC},			// Array Index 31
	{EHRPWM_01, 	PSC1, 	PD0, 	CSL_PSC_EHRPWM},		// Array Index 32
	{MMC_SD1, 		PSC1, 	PD0, 	CSL_PSC_MMCSD1},		// Array Index 33
	{UPP, 			PSC1,	PD0, 	CSL_PSC_UPP},			// Array Index 34
	{ECAP_012, 		PSC1, 	PD0, 	CSL_PSC_ECAP0_1_2},		// Array Index 35
	{EDMA1_TC0, 	PSC1, 	PD0, 	CSL_PSC_TC2},			// Array Index 36
	{SCR_F0, 		PSC1, 	PD0, 	CSL_PSC_SCRF0_SS},		// Array Index 37
	{SCR_F1, 		PSC1, 	PD0, 	CSL_PSC_SCRF1_SS},		// Array Index 38
	{SCR_F2, 		PSC1, 	PD0, 	CSL_PSC_SCRF2_SS},		// Array Index 39
	{SCR_F6, 		PSC1, 	PD0, 	CSL_PSC_SCRF6_SS},		// Array Index 40
	{SCR_F7, 		PSC1, 	PD0, 	CSL_PSC_SCRF7_SS},		// Array Index 41
	{SCR_F8, 		PSC1, 	PD0, 	CSL_PSC_SCRF8_SS},		// Array Index 42
	{BR_F7, 		PSC1, 	PD0, 	CSL_PSC_BR_F7},			// Array Index 43
	{L3_RAM, 		PSC1, 	PD1, 	CSL_PSC_SHRAM}			// Array Index 44
};

int WaitForPreviousTransition(CSL_PscRegsOvly pPSC, POWER_DOMAIN domainNum);
int ExecutePSCStateTransition(CSL_PscRegsOvly pPSC, POWER_DOMAIN domainNum);
int ChangePeripheralState(PERIPHERAL_NAME periphName, uint32 nextFieldValue);

int PSC_InitSystem(void)
{
	CSL_PscRegsOvly pPSC0 = (CSL_PscRegsOvly)CSL_PSC_0_REGS;
	CSL_PscRegsOvly pPSC1 = (CSL_PscRegsOvly)CSL_PSC_1_REGS;
	int tmpReturn = WaitForPreviousTransition(pPSC0, PD1);
	
	//DBG_Log(DRIVER_DEBUG_ID, VERB_LEVEL2, "PSC System Init!");
	if (tmpReturn == TRANSITION_SUCCESS)
	{
		// Ensure that the DSP memory and L3 memory power domains are on
		CSL_FINST(pPSC0->PDCTL1, PSC_PDCTL1_PDMODE, ON);	// DSP Core on, RAM on, periphery on
		CSL_FINST(pPSC0->PDCTL1, PSC_PDCTL1_EMUIHBIE, DISABLE);	// Emulation does not alter power domain
		CSL_FINST(pPSC0->PDCTL1, PSC_PDCTL1_NEXT, ON);	// Set next state to power domain on
		tmpReturn = ExecutePSCStateTransition(pPSC0, PD1);
	}
	
	if (tmpReturn == TRANSITION_SUCCESS)
	{
		tmpReturn = WaitForPreviousTransition(pPSC1, PD1);
	}
	if (tmpReturn == TRANSITION_SUCCESS)
	{
		CSL_FINST(pPSC1->PDCTL1, PSC_PDCTL1_PDMODE, ON);	// Shared RAM Core on, RAM on, periphery on
		CSL_FINST(pPSC1->PDCTL1, PSC_PDCTL1_EMUIHBIE, DISABLE);	// Emulation does not alter power domain
		CSL_FINST(pPSC1->PDCTL1, PSC_PDCTL1_NEXT, ON);	// Set next state to power domain on
		tmpReturn = ExecutePSCStateTransition(pPSC1, PD1);
	}
	
	return tmpReturn;
}

int PSC_EnablePeripheral(PERIPHERAL_NAME periphName)
{
	return ChangePeripheralState(periphName, CSL_PSC_MDCTL_NEXT_ENABLE);
}

int PSC_DisablePeripheral(PERIPHERAL_NAME periphName)
{
	return ChangePeripheralState(periphName, CSL_PSC_MDCTL_NEXT_DISABLE);
}

int WaitForPreviousTransition(CSL_PscRegsOvly pPSC, POWER_DOMAIN domainNum)
{
	int tmpReturn = TRANSITION_SUCCESS;		//Default to okay, prove failure
	volatile uint32 timeOut = 1000000;
	uint32 statMask = (domainNum == PD0) ? CSL_PSC_PTSTAT_GOSTAT0_MASK : CSL_PSC_PTSTAT_GOSTAT1_MASK;
	
	// Wait for any previous state transitions to complete
	while ( (--timeOut > 0) && ((pPSC->PTSTAT & statMask)) ) {}
	// Check to see if we exited the wait because we are good to go or because of a timeout
	if (timeOut == 0)
	{
		tmpReturn = TRANSITION_TIMEOUT_ERR;
	}
	
	return tmpReturn;
	
}

int ExecutePSCStateTransition(CSL_PscRegsOvly pPSC, POWER_DOMAIN domainNum)
{
	uint32 cmdMask = (domainNum == PD0) ? CSL_PSC_PTCMD_GO0_MASK : CSL_PSC_PTCMD_GO1_MASK;
	
	// Set the go bit for the desired power domain in the control register to initiate the transition
	pPSC->PTCMD |= cmdMask;
	return WaitForPreviousTransition(pPSC, domainNum);
}

int ChangePeripheralState(PERIPHERAL_NAME periphName, uint32 nextFieldValue)
{
	int tmpReturn = TRANSITION_SUCCESS;
	const PERIPHERAL_DESCRIPTOR* pDesc = &(periphArray[(uint32)(periphName)]);
	CSL_PscRegsOvly pPSC;
	uint32 MDCTLReg;
	
	// Double check to make sure the index table is correct and it is safe to use this entry
	if (pDesc->periphID != periphName)
	{
		return INVALID_PERIPHERAL_TABLE;
	}
	
	// Get a pointer to the corrrect power and sleep controller instance
	pPSC = pDesc->pscID == PSC0 ? (CSL_PscRegsOvly)CSL_PSC_0_REGS : (CSL_PscRegsOvly)CSL_PSC_1_REGS;
	// Wait for any previous transition to complete
	tmpReturn = WaitForPreviousTransition(pPSC, pDesc->pdID);
	
	if (tmpReturn == TRANSITION_SUCCESS)
	{
		// Set the next field for the correct MDCTL register
		MDCTLReg = pPSC->MDCTL[pDesc->lpscNum];
		MDCTLReg &= ~(CSL_PSC_MDCTL_NEXT_MASK);
		pPSC->MDCTL[pDesc->lpscNum] =  MDCTLReg | (nextFieldValue & CSL_PSC_MDCTL_NEXT_MASK);
		// Now execute the state transition on the correct power domain
		tmpReturn = ExecutePSCStateTransition(pPSC, pDesc->pdID);
	}
	
	return tmpReturn;
}


int PSC_LocalAssertDSP(PERIPHERAL_NAME periphName)
{
	CSL_PscRegsOvly pPSC = (CSL_PscRegsOvly)CSL_PSC_0_REGS;
	pPSC->MDCTL[CSL_PSC_DSP] &= ~(CSL_PSC_MDCTL_LRST_MASK);
	
	return TRANSITION_SUCCESS;
}

int PSC_LocalDeassertDSP(PERIPHERAL_NAME periphName)
{
	CSL_PscRegsOvly pPSC = (CSL_PscRegsOvly)CSL_PSC_0_REGS;
	pPSC->MDCTL[CSL_PSC_DSP] |= CSL_PSC_MDCTL_LRST_MASK;
	
	return TRANSITION_SUCCESS;
}

int PSC_LocalAssertARM(PERIPHERAL_NAME periphName)
{
	CSL_PscRegsOvly pPSC = (CSL_PscRegsOvly)CSL_PSC_0_REGS;
	pPSC->MDCTL[CSL_PSC_ARM] &= ~(CSL_PSC_MDCTL_LRST_MASK);

	return TRANSITION_SUCCESS;
}

int PSC_LocalDeassertARM(PERIPHERAL_NAME periphName)
{
	CSL_PscRegsOvly pPSC = (CSL_PscRegsOvly)CSL_PSC_0_REGS;
	pPSC->MDCTL[CSL_PSC_ARM] |= CSL_PSC_MDCTL_LRST_MASK;

	return TRANSITION_SUCCESS;
}

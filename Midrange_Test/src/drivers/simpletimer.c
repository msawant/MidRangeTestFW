#include "simpletimer.h"
#include "system.h"
#include <debug/knxdebug.h>
#include <ti/pspiom/cslr/cslr.h>
#include <ti/pspiom/cslr/soc_OMAPL138.h>
#include <ti/pspiom/cslr/cslr_tmr.h>

// Definition for the MAX 32 bit value


// Method responsible for configuring the specified timer to interrupt in a given period
StatusCode TMR_Init(TimerID tID, TimerType tType, float64 tPeriod)
{
	CSL_TmrRegsOvly tmrRegs = NULL;
	
	DBG_LogUint16(DRIVER_DEBUG_ID, VERB_LEVEL1, "Timer[%d] Init!", tID);
	
	// Get the base timer
	switch (tID)
	{
#if defined (OMAP_DSP)		// Timers 0 & 1 belong to the DSP
		case TMR_0_LOWER:
		case TMR_0_UPPER:
			tmrRegs = (CSL_TmrRegsOvly)CSL_TMR_0_REGS;
		break;
		
		case TMR_1_LOWER:
		case TMR_1_UPPER:
			tmrRegs = (CSL_TmrRegsOvly)CSL_TMR_1_REGS;
		break;
		
#elif defined (OMAP_ARM)	// Timers 2 & 3 belong to the ARM
		
		case TMR_2_LOWER:
		case TMR_2_UPPER:
			tmrRegs = (CSL_TmrRegsOvly)CSL_TMR_2_REGS;
		break;
		
		case TMR_3_LOWER:
		case TMR_3_UPPER:
			tmrRegs = (CSL_TmrRegsOvly)CSL_TMR_3_REGS;
		break;
#endif
		
		default:
			// Bad timer ID value passed in
			DBG_Log(DRIVER_DEBUG_ID, VERB_LEVEL1, "Invalid Timer ID!");
			return CIP_GRC_INVALID_PARAMETER;
	} 
	
	// Make sure the timer peripheral is in 32-bit unchained mode
	CSL_FINST(tmrRegs->TGCR, TMR_TGCR_TIMMODE, 32BIT_UNCHAIN);
	
	// Start by holding the timer in question in reset
	if (tID < TMR_UPPER)
	{
		CSL_FINST(tmrRegs->TGCR, TMR_TGCR_TIM12RS, RESET);
	}
	else
	{
		CSL_FINST(tmrRegs->TGCR, TMR_TGCR_TIM34RS, RESET);
	}

	
	// Set the TCR Regs first
	if (tID < TMR_UPPER)
	{
		// Be sure to disable the capture mode
		CSL_FINST(tmrRegs->TCR, TMR_TCR_CAPMODE12, DISABLE);
		// Be sure the timer reset by reads (we will use this later to reset)
		CSL_FINST(tmrRegs->TCR, TMR_TCR_READRSTMODE12, RESET);
		// Be sure timer count gating is not enabled
		CSL_FINST(tmrRegs->TCR, TMR_TCR_TIEN12, NOTGATED);
		// Set the clock source to the internal timer
		CSL_FINST(tmrRegs->TCR, TMR_TCR_CLKSRC12, INTERNAL);
		// Set the timer mode
		if (tType == TMR_TYPE_CONTINUOUS)
		{
			CSL_FINST(tmrRegs->TCR, TMR_TCR_ENAMODE12, EN_CONT);
		}
		else
		{
			CSL_FINST(tmrRegs->TCR, TMR_TCR_ENAMODE12, EN_ONCE);
		}
	}
	else
	{
		// Be sure to disable the capture mode
		CSL_FINST(tmrRegs->TCR, TMR_TCR_CAPMODE34, DISABLE);
		//  Be sure the timer reset by reads (we will use this later to reset)
		CSL_FINST(tmrRegs->TCR, TMR_TCR_READRSTMODE34, RESET);
		// Be sure timer count gating is not enabled
		CSL_FINST(tmrRegs->TCR, TMR_TCR_TIEN34, NOTGATED);
		// Set the clock source to the internal timer
		CSL_FINST(tmrRegs->TCR, TMR_TCR_CLKSRC34, INTERNAL);
		// Set the timer mode
		if (tType == TMR_TYPE_CONTINUOUS)
		{
			CSL_FINST(tmrRegs->TCR, TMR_TCR_ENAMODE34, EN_CONT);
		}
		else
		{
			CSL_FINST(tmrRegs->TCR, TMR_TCR_ENAMODE34, EN_ONCE);
		}
	}

	// Now configure the period register which will determine the frequency of the ticks. Also preload the reload register
#if defined (OMAP_DSP)		// Timers 0 & 1 belong to the DSP
	// In the case of the DSP the timer 0/1 peripherals are clocked from the "auxclock"
	tPeriod *= SYS_OSC_IN_FREQ;
	// Now just to be sure we will have to clip the period to 32-bits
	tPeriod = (tPeriod < TYPES_UINT32_MAX) ? tPeriod : UINT32_MAX;
	DBG_LogUint32Float64(DRIVER_DEBUG_ID, VERB_LEVEL2, "ACTUAL Timer[%d] period = %f", tID, (float64)(tPeriod / SYS_OSC_IN_FREQ));
#elif defined (OMAP_ARM)	// Timers 2 & 3 belong to the ARM
	// In the case of the ARM the timer 2/3 peripherals are clocked from sysclk2
	tPeriod *= SYS_SYSCLK2_FREQ;
	// Now just to be sure we will have to clip the period to 32-bits
	tPeriod = (tPeriod < TYPES_UINT32_MAX) ? tPeriod : UINT32_MAX;
	DBG_LogUint32Float64(DRIVER_DEBUG_ID, VERB_LEVEL2, "ACTUAL Timer[%d] period = %f", tID, (float64)(tPeriod / SYS_SYSCLK2_FREQ));
#endif
	// Set the period and reload registers
	if (tID < TMR_UPPER)
	{
		tmrRegs->PRD12 = (uint32)tPeriod;
	}
	else
	{
		tmrRegs->PRD34 = (uint32)tPeriod;
	}
	// Be sure to clear the timer value
	if (tID < TMR_UPPER)
	{
		tmrRegs->TIM12 = 0;
	}
	else
	{
		tmrRegs->TIM34 = 0;
	}
	
	return CIP_GRC_SUCCESS;
}

// Method to start a given timer ID. Note timer must be initialized first
void TMR_Start(TimerID tID)
{
	CSL_TmrRegsOvly tmrRegs = NULL;
	
	// Get the base timer
	switch (tID)
	{
#if defined (OMAP_DSP)		// Timers 0 & 1 belong to the DSP
		case TMR_0_LOWER:
		case TMR_0_UPPER:
			tmrRegs = (CSL_TmrRegsOvly)CSL_TMR_0_REGS;
		break;
		
		case TMR_1_LOWER:
		case TMR_1_UPPER:
			tmrRegs = (CSL_TmrRegsOvly)CSL_TMR_1_REGS;
		break;
		
#elif defined (OMAP_ARM)	// Timers 2 & 3 belong to the ARM
		
		case TMR_2_LOWER:
		case TMR_2_UPPER:
			tmrRegs = (CSL_TmrRegsOvly)CSL_TMR_2_REGS;
		break;
		
		case TMR_3_LOWER:
		case TMR_3_UPPER:
			tmrRegs = (CSL_TmrRegsOvly)CSL_TMR_3_REGS;
		break;
#endif
		
		default:
			// Bad timer ID value passed in
			DBG_LogUint16(DRIVER_DEBUG_ID, VERB_LEVEL1, "Attempted to Start Invalid Timer ID %d!", tID);
			return;
	} 
	if (tID < TMR_UPPER)
	{
		CSL_FINST(tmrRegs->TGCR, TMR_TGCR_TIM12RS, NO_RESET);
	}
	else
	{
		CSL_FINST(tmrRegs->TGCR, TMR_TGCR_TIM34RS, NO_RESET);
	}
}

// Method to stop a given timer ID. Note timer must be initialized first
void TMR_Stop(TimerID tID)
{
	CSL_TmrRegsOvly tmrRegs = NULL;
	
	// Get the base timer
	switch (tID)
	{
#if defined (OMAP_DSP)		// Timers 0 & 1 belong to the DSP
		case TMR_0_LOWER:
		case TMR_0_UPPER:
			tmrRegs = (CSL_TmrRegsOvly)CSL_TMR_0_REGS;
		break;
		
		case TMR_1_LOWER:
		case TMR_1_UPPER:
			tmrRegs = (CSL_TmrRegsOvly)CSL_TMR_1_REGS;
		break;
		
#elif defined (OMAP_ARM)	// Timers 2 & 3 belong to the ARM
		
		case TMR_2_LOWER:
		case TMR_2_UPPER:
			tmrRegs = (CSL_TmrRegsOvly)CSL_TMR_2_REGS;
		break;
		
		case TMR_3_LOWER:
		case TMR_3_UPPER:
			tmrRegs = (CSL_TmrRegsOvly)CSL_TMR_3_REGS;
		break;
#endif
		
		default:
			// Bad timer ID value passed in
			DBG_LogUint16(DRIVER_DEBUG_ID, VERB_LEVEL1, "Attempted to Start Invalid Timer ID %d!", tID);
			return;
	} 
	if (tID < TMR_UPPER)
	{
		CSL_FINST(tmrRegs->TGCR, TMR_TGCR_TIM12RS, RESET);
	}
	else
	{
		CSL_FINST(tmrRegs->TGCR, TMR_TGCR_TIM34RS, RESET);
	}
}

// Method to reset/reload the timer
void TMR_Reset(TimerID tID)
{
	CSL_TmrRegsOvly tmrRegs = NULL;
	
	// Get the base timer
	switch (tID)
	{
#if defined (OMAP_DSP)		// Timers 0 & 1 belong to the DSP
		case TMR_0_LOWER:
		case TMR_0_UPPER:
			tmrRegs = (CSL_TmrRegsOvly)CSL_TMR_0_REGS;
		break;
		
		case TMR_1_LOWER:
		case TMR_1_UPPER:
			tmrRegs = (CSL_TmrRegsOvly)CSL_TMR_1_REGS;
		break;
		
#elif defined (OMAP_ARM)	// Timers 2 & 3 belong to the ARM
		
		case TMR_2_LOWER:
		case TMR_2_UPPER:
			tmrRegs = (CSL_TmrRegsOvly)CSL_TMR_2_REGS;
		break;
		
		case TMR_3_LOWER:
		case TMR_3_UPPER:
			tmrRegs = (CSL_TmrRegsOvly)CSL_TMR_3_REGS;
		break;
#endif
		
		default:
			// Bad timer ID value passed in
			DBG_LogUint16(DRIVER_DEBUG_ID, VERB_LEVEL1, "Attempted to Start Invalid Timer ID %d!", tID);
			return;
	}
	// Put the timer in reset
	CSL_FINST(tmrRegs->TGCR, TMR_TGCR_TIM12RS, RESET);
	// Clear the timer value
	if (tID < TMR_UPPER)
	{
		tmrRegs->TIM12 = 0;
	}
	else
	{
		tmrRegs->TIM34 = 0;
	}
	// Remove the reset and let the timer free run
	CSL_FINST(tmrRegs->TGCR, TMR_TGCR_TIM12RS, NO_RESET);
}

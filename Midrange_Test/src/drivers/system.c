#include "system.h"
#include <drivers/psc.h>
#include <drivers/edma.h>
#include <debug/knxdebug.h>
#include <ti/pspiom/cslr/cslr.h>
#include <ti/pspiom/cslr/soc_OMAPL138.h>
#include <ti/pspiom/cslr/cslr_syscfg0_OMAPL138.h>
#include <DataTypes.h>

//////////////////// MSTPRI REGISTER CONFIGURATION ////////////////////
// EDMA0 Transfer Controller 0 and EDMA1 Transfer Controller
/// to be the highest master in the system (Priority = 0)
// Move the EDMA0 Transfer Controller 1 to be the next 
// highest (just above ARM/DSP)  (Priority = 1)
// Next are the ARM and DSP (Priority = 2)
// Next is the EDMA DMA (Priority = 3)
// And finally the LCDC (Priority = 4)
// Move unused stuff like the SATA, UPP, VPIF, PRUs, USBs, UHPI 
// to the lowest priority (Priority = 7)
#define SYSCFG_MSTPRI0_REG (0x44772222)
#define SYSCFG_MSTPRI1_REG (0x77401077)
#define SYSCFG_MSTPRI2_REG (0x47707703)
///////////////////////////////////////////////////////////////////////

// SYSCFG unlock/lock values for the kick registers
#define SYSCFG_KICK0_UNLOCK (0x83E70B13)
#define SYSCFG_KICK1_UNLOCK (0x95A4F1E0)
#define SYSCFG_KICK0_LOCK (0x0)
#define SYSCFG_KICK1_LOCK (0x0)

void SYS_Init(void)
{
	CSL_SyscfgRegsOvly syscfgRegs = (CSL_SyscfgRegsOvly)CSL_SYSCFG_0_REGS;
		
	// Initialize the kinetix debug system
	DBG_Init();
	DBG_Log(DRIVER_DEBUG_ID, VERB_LEVEL2, "System Init!");
	
	// Enable all important system devices in the PSC
	PSC_InitSystem();
	
	// Configure the switched central resource controller master priorities
	SYS_ConfigUnlock();
	syscfgRegs->MSTPRI0 = SYSCFG_MSTPRI0_REG;
	syscfgRegs->MSTPRI1 = SYSCFG_MSTPRI1_REG;
	syscfgRegs->MSTPRI2 = SYSCFG_MSTPRI2_REG;
	SYS_ConfigLock();
	
	// Initialize the EDMA driver
	EDMA_Init();
}

static int32 unlockLevel = 0;
// Method responsible for locking the syscfg registers.
void SYS_ConfigUnlock(void)
{
	CSL_SyscfgRegsOvly syscfgRegs = (CSL_SyscfgRegsOvly)CSL_SYSCFG_0_REGS;
	syscfgRegs->KICK0R = SYSCFG_KICK0_UNLOCK;
	syscfgRegs->KICK1R = SYSCFG_KICK1_UNLOCK;
	unlockLevel++;
}

// Method responsible for locking the syscfg registers. 
void SYS_ConfigLock(void)
{
	CSL_SyscfgRegsOvly syscfgRegs = (CSL_SyscfgRegsOvly)CSL_SYSCFG_0_REGS;
	
	if (--unlockLevel <= 0)
	{
		// We are finally unlocked all the way. Or someone called it just because which is okay. Lock
		syscfgRegs->KICK0R = SYSCFG_KICK0_LOCK;
		syscfgRegs->KICK1R = SYSCFG_KICK1_LOCK;
		unlockLevel = 0;	
	}
	else
	{
		// Still in a nested unlock
		unlockLevel--;	
	}
}

// Method to reboot the OMAP cores
#define T1_WDTCR (*((Uint32*)0x01C21028))
#define T1_TGCR (*((Uint32*)0x01C21024))
#define T1_TIM12 (*((Uint32*)0x01C21010))
#define T1_TIM34 (*((Uint32*)0x01C21014))
#define T1_PRD12 (*((Uint32*)0x01C21018))
#define T1_PRD34 (*((Uint32*)0x01C2101C))
void SYS_Reboot(void)
{
	// Set timer is watchdog mode timers stopped
	T1_TGCR = 0x00000008;
	// Set period registers to something (small) and clear the timer counter registers
	T1_TIM12 = 0;
	T1_TIM34 = 0;
	T1_PRD12 = 0x100;
	T1_PRD34 = 0;
	// Enable the timers (keep watchdog mode)
	T1_TGCR = 0x0000000B;
	// Enable the watchdog and set the first part of the special key
	T1_WDTCR = 0xA5C64000;
	// Set the second part of the special key (keep WD enabled)
	T1_WDTCR = 0xDA7E4000;
}


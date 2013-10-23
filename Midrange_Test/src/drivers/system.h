#ifndef SYSTEM_H_
#define SYSTEM_H_

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////////
////////////////////////// SYSTEM CLOCKING DEFINITIONS ///////////////////////////
//////////////////////////////////////////////////////////////////////////////////
#define SYS_OSC_IN_FREQ (24000000)
#define SYS_MAIN_CLOCK_FREQ (300000000)
#define SYS_SYSCLK2_FREQ (SYS_MAIN_CLOCK_FREQ / 2)

// Method responsible for setting up the basic system level variables/drivers/etc.
void SYS_Init(void);

// Method responsible for locking the syscfg registers.
void SYS_ConfigUnlock(void);

// Method responsible for locking the syscfg registers. 
void SYS_ConfigLock(void);

// Method to reboot
void SYS_Reboot(void);

#ifdef __cplusplus
}
#endif

#endif /*SYSTEM_H_*/

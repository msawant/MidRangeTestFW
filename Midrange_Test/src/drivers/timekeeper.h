/*
 * timekeeper.h
 *
 *  Created on: Oct 15, 2013
 *      Author: msawant
 */

#ifndef TIMEKEEPER_H_
#define TIMEKEEPER_H_

#include <DataTypes.h>

typedef struct{
	volatile uint16 LOCAL_TIME_OS_LL;
	volatile uint16 LOCAL_TIME_OS_LH;
	volatile uint16 LOCAL_TIME_OS_HL;
	volatile uint16 LOCAL_TIME_OS_HH;
	uint16 SUP_SELECT;
	volatile uint16 SUP_TIMER;
	volatile uint16 SUP_COUNTER;
	uint16 BLANK1;
	volatile uint16 SYSTIME0_TS_LL;
	volatile uint16 SYSTIME0_TS_LH;
	volatile uint16 SYSTIME0_TS_HL;
	volatile uint16 SYSTIME0_TS_HH;
	volatile uint16 SYSTIME1_TS_LL;
	volatile uint16 SYSTIME1_TS_LH;
	volatile uint16 SYSTIME1_TS_HL;
	volatile uint16 SYSTIME1_TS_HH;
	volatile uint16 SYSTIME2_TS_LL;
	volatile uint16 SYSTIME2_TS_LH;
	volatile uint16 SYSTIME2_TS_HL;
	volatile uint16 SYSTIME2_TS_HH;
	volatile uint16 SYSTIME3_TS_LL;
	volatile uint16 SYSTIME3_TS_LH;
	volatile uint16 SYSTIME3_TS_HL;
	volatile uint16 SYSTIME3_TS_HH;
	volatile uint16 SYSTIME4_TS_LL;
	volatile uint16 SYSTIME4_TS_LH;
	volatile uint16 SYSTIME4_TS_HL;
	volatile uint16 SYSTIME4_TS_HH;
	uint16 BLANK2;
	uint16 BLANK3;
	uint16 BLANK4;
	uint16 BLANK5;
	volatile uint16 DSL_SUP_DLY_AXIS_A;
	volatile uint16 DSL_SUP_DLY_AXIS_B;
	volatile uint16 SUP_TEST_PERIOD;
	uint16 BLANK6;
	volatile uint16 ID;
	volatile uint16 SCRATCHPAD;
}TimeKeeper_Regs;

typedef volatile TimeKeeper_Regs             *TimeKeeper_RegsOvly;

#ifdef __cplusplus
extern "C" {
#endif

int GetTimeKeeperModuleID();
int TestTimeKeeperScratchPad();
int SetPseudoTimePeriodUSec(unsigned int );
int initTimekeeperPsudoSup();

#ifdef __cplusplus
}
#endif

#endif /* TIMEKEEPER_H_ */

/*
 * timekeeper.c
 *
 *  Created on: Oct 15, 2013
 *      Author: msawant
 */

#include "drivers/kmcl2.h"
#include "drivers/timekeeper.h"

TimeKeeper_RegsOvly TimeKeeperRegs = (TimeKeeper_RegsOvly) KNX_IP_TIMEKEEPER;

int GetTimeKeeperModuleID(){
	return TimeKeeperRegs->ID;
}

int TestTimeKeeperScratchPad(){
	int stat;
	uint16 test_dat = 0xbeef;
	TimeKeeperRegs->SCRATCHPAD = test_dat;
	if(test_dat==TimeKeeperRegs->SCRATCHPAD){
		stat=1;
	}
	else{
		stat = 0;
	}
	return stat;
}

int SetPseudoTimePeriodUSec(unsigned int x){
	TimeKeeperRegs->SUP_TEST_PERIOD = x;
	return TimeKeeperRegs->SUP_TEST_PERIOD;
}

int initTimekeeperPsudoSup(){
	TimeKeeperRegs->SUP_SELECT=0x002; //Set Timkeeper to generate internal SUP
	return 1;
}




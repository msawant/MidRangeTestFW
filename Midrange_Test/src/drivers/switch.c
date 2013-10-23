/*
 * switch.c
 *
 *  Created on: Oct 18, 2013
 *      Author: miglab
 */
#include "drivers/kmcl2.h"
#include "drivers/switch.h"


EthernetSwitchRegsOvly etherRegs = (EthernetSwitchRegsOvly) RA_SWITCH;


int SetupSwitchForTest(){
	etherRegs->ADDEND_HI=0x0001;
	return etherRegs->ADDEND_HI;
}


int RunSwitchTestCase(){
	SetupSwitchForTest();
	return 1;
}

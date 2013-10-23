/*
 * TimeKeeperTestCase.cpp
 *
 *  Created on: Oct 15, 2013
 *      Author: msawant
 */


#include "TimeKeeperTestCase.hpp"
#include "drivers/timekeeper.h"
#include "drivers/switch.h"

//Constructor
TimeKeeperTestCase::TimeKeeperTestCase()
:TestCase(TEST_CASE_ID_TIMEKEEPER_TEST){
 //do nothing
}

TimeKeeperTestCase::~TimeKeeperTestCase(){
	//do nothing
}


void TimeKeeperTestCase::Run(
int16 Argc,					// number of arguments
std::string* Argv,			// pointer to array variable argument
std::string &rResponseText	// reference string to place the response text
)

{
	// Check to make sure the correct number of arguments was passed in for
	// this test case.
	if (Argc == TIMEKEEPER_TEST_REQUIRED_ARGS)
	{
		int code = 0;
		char responseBuffer[200];
		sscanf(Argv[1].c_str(),"%X",&code);
		switch (code) {
			case 1:
				sprintf(responseBuffer, "Timekeeper ID is %X",GetTimeKeeperModuleID());
				break;
			case 2:
				sprintf(responseBuffer, "Setting up Ethernet ADDEND_LO signal to %X for test",SetupSwitchForTest());
				break;
			case 3:
				break;
			case 4:
				break;
			default:
				sprintf(responseBuffer, "Nothing Done. No such Case");
				break;
		}

		rResponseText = responseBuffer;
	}
	// too few or too many parameters
	else
	{
		rResponseText = "-03";
	}
	return;
}



/*
 * MasterTestCase.cpp
 *
 *  Created on: Oct 11, 2013
 *      Author: miglab
 */


#include "MasterTestCase.hpp"
#include "drivers/kmcl2_config.h"


//Constructor
MasterTestCase::MasterTestCase()
:TestCase(TEST_CASE_ID_MASTER_TEST){
 //do nothing
}

MasterTestCase::~MasterTestCase(){
	//do nothing
}


void MasterTestCase::Run(
int16 Argc,					// number of arguments
std::string* Argv,			// pointer to array variable argument
std::string &rResponseText	// reference string to place the response text
)

{
	// Check to make sure the correct number of arguments was passed in for
	// this test case.
	if (Argc == MASTER_TEST_REQUIRED_ARGS)
	{
		int code = 0;
		int revId = 0;
		char responseBuffer[200];
		sscanf(Argv[1].c_str(),"%X",&code);
		switch (code) {
			case 1:
				revId = kmcl2_config_get_rev_id();
				sprintf(responseBuffer, "KMCL Revision is %X", revId);
				break;
			case 2:
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



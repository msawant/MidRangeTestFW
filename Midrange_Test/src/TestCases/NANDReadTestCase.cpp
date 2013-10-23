#include "NANDReadTestCase.hpp"

#include <stdio.h>

// class constructor
NANDReadTestCase::NANDReadTestCase() 
: TestCase(TEST_CASE_ID_NAND_READ)
{
	// do nothing
}

// class destructor
NANDReadTestCase::~NANDReadTestCase()
{
}

/////////////////////////////////////////////////////////////////////////////
// The DDR Read test case reads the memory data at the address passed in   //
// the second argument.  A successful read will return the test case       //
// number followed by the memory data in the rResponseText string.         //
/////////////////////////////////////////////////////////////////////////////
void NANDReadTestCase::Run
(
	int16 Argc, 				// number of arguments
	std::string* Argv,			// pointer to array variable argument 
	std::string &rResponseText	// reference string to place the response text 
)
{
	// Check to make sure the correct number of arguments was passed in for
	// this test case.
	if (Argc == NAND_READ_REQUIRED_ARGS)
	{
		uint32 memAddress = 0;
		uint8 memData = 0;
		char responseBuffer[32];
		
		// read the memory at the hex address in Argv
		//std::stringstream mystream(Argv[DDR_READ_ARG_READ_ADDRESS]);
		//mystream >> hex >> memAddress;
		sscanf(Argv[1].c_str(),"%X",&memAddress);
		memData = READMEM8(memAddress);
		
		// format and copy the response
		//std::stringstream myOstream(rResponseText);
		//myOstream << dec << TEST_CASE_ID_DDR_READ << hex << memData;
		sprintf(responseBuffer, "%d %X",TEST_CASE_ID_NAND_READ,memData);
		rResponseText = responseBuffer;
	}
	// too few or too many parameters
	else
	{
		rResponseText = "-03";
	}
	return;
}

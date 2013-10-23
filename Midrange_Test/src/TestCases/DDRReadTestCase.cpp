#include "DDRReadTestCase.hpp"

#include <stdio.h>

// class constructor
DDRReadTestCase::DDRReadTestCase() 
: TestCase(TEST_CASE_ID_DDR_READ)
{
	// do nothing
}

// class destructor
DDRReadTestCase::~DDRReadTestCase()
{
}

/////////////////////////////////////////////////////////////////////////////
// The DDR Read test case reads the memory data at the address passed in   //
// the second argument.  A successful read will return the test case       //
// number followed by the memory data in the rResponseText string.         //
/////////////////////////////////////////////////////////////////////////////
void DDRReadTestCase::Run
(
	int16 Argc, 				// number of arguments
	std::string* Argv,			// pointer to array variable argument 
	std::string &rResponseText	// reference string to place the response text 
)
{
	// Check to make sure the correct number of arguments was passed in for
	// this test case.
	if (Argc == DDR_READ_REQUIRED_ARGS)
	{

		uint32 memAddress;
		uint32 memData;
		char responseBuffer[32];
		
		// read the memory at the hex address in Argv
		//std::stringstream mystream(Argv[DDR_READ_ARG_READ_ADDRESS]);
		//mystream >> hex >> memAddress;
		sscanf(Argv[1].c_str(),"%X",&memAddress);
		memData = READMEM32(memAddress);
		
		// format and copy the response
		//std::stringstream myOstream(rResponseText);
		//myOstream << dec << TEST_CASE_ID_DDR_READ << hex << memData;
		sprintf(responseBuffer, "%d %X",TEST_CASE_ID_DDR_READ,memData);
		printf("%d %X",TEST_CASE_ID_DDR_READ,memData);
		rResponseText = responseBuffer;
	}
	// too few or too many parameters
	else
	{
		rResponseText = "-03";
	}
	return;
}

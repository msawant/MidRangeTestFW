#include "Write16TestCase.hpp"

#include <stdio.h>

// class constructor
Write16TestCase::Write16TestCase() 
: TestCase(TEST_CASE_ID_16_WRITE)
{
	// do nothing
}

// class destructor
Write16TestCase::~Write16TestCase()
{
}

/////////////////////////////////////////////////////////////////////////////
// The DDR Write test case reads the memory data at the address passed in   //
// the second argument.  A successful read will return the test case       //
// number followed by the memory data in the rResponseText string.         //
/////////////////////////////////////////////////////////////////////////////
void Write16TestCase::Run
(
	int16 Argc, 				// number of arguments
	std::string* Argv,			// pointer to array variable argument 
	std::string &rResponseText	// reference string to place the response text 
)
{
	// Check to make sure the correct number of arguments was passed in for
	// this test case.
	if (Argc == WRITE_16_REQUIRED_ARGS)
	{
		uint32 memAddress = 0;
		uint16 memData = 0;
//		uint16 memWrittenData=0;
		char responseBuffer[32];
		
		// read the memory at the hex address in Argv
		//std::stringstream mystream(Argv[DDR_WRITE_ARG_WRITE_ADDRESS]);
		//mystream >> hex >> memAddress;
		sscanf(Argv[1].c_str(),"%X",&memAddress);
		sscanf(Argv[2].c_str(),"%X",&memData);
		
		WRITEMEM16(memAddress, memData);
		//memWrittenData = READMEM16(memAddress);
		// format and copy the response
		//std::stringstream myOstream(rResponseText);
		//myOstream << dec << TEST_CASE_ID_DDR_WRITE << hex << memData;
		sprintf(responseBuffer, "%d %s",TEST_CASE_ID_16_WRITE,"Done");
		rResponseText = responseBuffer;
	}
	// too few or too many parameters
	else
	{
		rResponseText = "-03";
	}
	return;
}

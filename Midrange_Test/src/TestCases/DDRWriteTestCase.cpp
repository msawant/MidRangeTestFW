#include "DDRWriteTestCase.hpp"

#include <stdio.h>

// class constructor
DDRWriteTestCase::DDRWriteTestCase() 
: TestCase(TEST_CASE_ID_DDR_WRITE)
{
	// do nothing
}

// class destructor
DDRWriteTestCase::~DDRWriteTestCase()
{
}

/////////////////////////////////////////////////////////////////////////////
// The DDR Write test case reads the memory data at the address passed in   //
// the second argument.  A successful read will return the test case       //
// number followed by the memory data in the rResponseText string.         //
/////////////////////////////////////////////////////////////////////////////
void DDRWriteTestCase::Run
(
	int16 Argc, 				// number of arguments
	std::string* Argv,			// pointer to array variable argument 
	std::string &rResponseText	// reference string to place the response text 
)
{
	// Check to make sure the correct number of arguments was passed in for
	// this test case.
	if (Argc == DDR_WRITE_REQUIRED_ARGS)
	{
		uint32 memAddress = 0;
		uint32 memData = 0;
		uint32 memWrittenData=0;
		char responseBuffer[32];
		
		// read the memory at the hex address in Argv
		//std::stringstream mystream(Argv[DDR_WRITE_ARG_WRITE_ADDRESS]);
		//mystream >> hex >> memAddress;
		sscanf(Argv[1].c_str(),"%X",&memAddress);
		sscanf(Argv[2].c_str(),"%X",&memData);
		WRITEMEM32(memAddress, memData);
		memWrittenData = READMEM32(memAddress);
		// format and copy the response
		//std::stringstream myOstream(rResponseText);
		//myOstream << dec << TEST_CASE_ID_DDR_WRITE << hex << memData;
		sprintf(responseBuffer, "%d %X",TEST_CASE_ID_DDR_WRITE,memWrittenData);
		rResponseText = responseBuffer;
	}
	// too few or too many parameters
	else
	{
		rResponseText = "-03";
	}
	return;
}

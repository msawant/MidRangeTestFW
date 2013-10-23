#include "DDRWriteZerosTestCase.hpp"
#include "utils/Io_Stream.hpp"

#include <stdio.h>

// class constructor
DDRWriteZerosTestCase::DDRWriteZerosTestCase() 
: TestCase(TEST_CASE_ID_DDR_WRITE_ZEROS)
{
	// do nothing
}

// class destructor
DDRWriteZerosTestCase::~DDRWriteZerosTestCase()
{
}

/////////////////////////////////////////////////////////////////////////////
// The DDR Write test case reads the memory data at the address passed in   //
// the second argument.  A successful read will return the test case       //
// number followed by the memory data in the rResponseText string.         //
/////////////////////////////////////////////////////////////////////////////
void DDRWriteZerosTestCase::Run
(
	int16 Argc, 				// number of arguments
	std::string* Argv,			// pointer to array variable argument 
	std::string &rResponseText	// reference string to place the response text 
)
{
	// Check to make sure the correct number of arguments was passed in for
	// this test case.
	if (Argc == DDR_WRITE_ZEROS_REQUIRED_ARGS)
	{

		uint32 memData = 0;
//		uint32 memAddress = 0;
//		uint32 dataWrite = 0;
//		uint32 dataRead = 0;
		Io_Stream* pIo_Stream = new Io_Stream();
		
		char responseBuffer[32];
		
		// read the memory at the hex address in Argv
		//std::stringstream mystream(Argv[DDR_WRITE_ARG_WRITE_ADDRESS]);
		//mystream >> hex >> memAddress;
		//sscanf(Argv[1].c_str(),"%X",&memStartAddress);
		//sscanf(Argv[2].c_str(),"%X",&memEndAddress);
		
		//Erase all memory to zero
		WriteAllDDRZero();

		pIo_Stream->Io_StreamPutLine("Writing Zeros Test complete without errors");				
		// format and copy the response
		//std::stringstream myOstream(rResponseText);
		//myOstream << dec << TEST_CASE_ID_DDR_WRITE << hex << memData;
		sprintf(responseBuffer, "%d %X",TEST_CASE_ID_DDR_WRITE_ZEROS,memData);
		rResponseText = responseBuffer;
	}
	// too few or too many parameters
	else
	{
		rResponseText = "-03";
	}
	return;
}

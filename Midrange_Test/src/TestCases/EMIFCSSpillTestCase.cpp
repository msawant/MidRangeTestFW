#include "EMIFCSSpillTestCase.hpp"
#include "utils/Io_Stream.hpp"

#include <stdio.h>

// class constructor
EMIFCSSpillTestCase::EMIFCSSpillTestCase() 
: TestCase(TEST_CASE_ID_EMIF_CS_SPILL)
{
	// do nothing
}

// class destructor
EMIFCSSpillTestCase::~EMIFCSSpillTestCase()
{
}

/////////////////////////////////////////////////////////////////////////////
// The EMIF Spill test case starts reading the memory data at the address  // 
// in the CS2 space and then proceeds to CS3 space.  					   //	
// This test runs in while loop to enable probing. 					       //
/////////////////////////////////////////////////////////////////////////////
void EMIFCSSpillTestCase::Run
(
	int16 Argc, 				// number of arguments
	std::string* Argv,			// pointer to array variable argument 
	std::string &rResponseText	// reference string to place the response text 
)
{
	// Check to make sure the correct number of arguments was passed in for
	// this test case.
	if (Argc == EMIF_CS_SPILL_REQUIRED_ARGS)
	{


		uint32 memAddress = 0;

		uint32 dataRead = 0;
		Io_Stream* pIo_Stream = new Io_Stream();
		
		char responseBuffer[32];
		
		while(1){
			//for(memAddress=0x61FFFFF0; memAddress<=0x62000011; memAddress+=4) {
				dataRead = READMEM32(0x61FFFFF0);
				dataRead = READMEM32(0x61FFFFF4);
				dataRead = READMEM32(0x61FFFFF8);
				dataRead = READMEM32(0x61FFFFFC);
				dataRead = READMEM32(0x62000000);
				dataRead = READMEM32(0x62000004);
				//printf("reading %X value: %X \n", memAddress, dataRead);
	//		}
			printf("reading %X value: %X \n", memAddress, dataRead);
		}
		

//		sprintf(responseBuffer, "%d %X",TEST_CASE_ID_EMIF_CS_SPILL,memData);
		rResponseText = responseBuffer;
	}
	// too few or too many parameters
	else
	{
		rResponseText = "-03";
	}
	return;
}

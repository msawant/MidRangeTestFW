#include "DDRWalkingOnesTestCase.hpp"
#include "utils/Io_Stream.hpp"

#include <stdio.h>

// class constructor
DDRWalkingOnesTestCase::DDRWalkingOnesTestCase() 
: TestCase(TEST_CASE_ID_DDR_WALKING_ONES)
{
	// do nothing
}

// class destructor
DDRWalkingOnesTestCase::~DDRWalkingOnesTestCase()
{
}

/////////////////////////////////////////////////////////////////////////////
// The DDR Write test case reads the memory data at the address passed in   //
// the second argument.  A successful read will return the test case       //
// number followed by the memory data in the rResponseText string.         //
/////////////////////////////////////////////////////////////////////////////
void DDRWalkingOnesTestCase::Run
(
	int16 Argc, 				// number of arguments
	std::string* Argv,			// pointer to array variable argument 
	std::string &rResponseText	// reference string to place the response text 
)
{
	// Check to make sure the correct number of arguments was passed in for
	// this test case.
	if (Argc == DDR_WALKING_ONES_REQUIRED_ARGS)
	{

		uint32 memData = 0;
		uint32 memAddress = 0;
		uint32 dataWrite = 0;
		uint32 dataRead = 0;
		
		Io_Stream* pIo_Stream = new Io_Stream();
		
		char responseBuffer[32];
		
		//Erase all memory to zero
		WriteAllDDRZero();
		uint32 compareBit =0;
		for(memAddress=DDR_START_ADDR; memAddress<=DDR_END_ADDR; memAddress+=4) {
			
			dataWrite = 0x00000001;
			
			
			for (uint16 bit=0;bit<32;bit++) {
				WRITEMEM32(memAddress, dataWrite); 
				dataRead = READMEM32(memAddress);
				
				if(dataRead!=dataWrite) {
					pIo_Stream->Io_StreamPutLine("Walking Ones failed at memory location");
					printf("Walking Ones failed at memory location %X", memAddress);
					break;
				}
				else {
				}
		
				dataWrite = (dataWrite << 1) | (dataWrite >> (32 - 1));
				
			}
			WRITEMEM32(memAddress, 0x00000000);
	
			uint32 totalMemory	= (uint32) DDR_END_ADDR - (uint32) DDR_START_ADDR;
			uint32 memWritten = (uint32) memAddress - (uint32) DDR_START_ADDR;
//			uint32 intPercentCompete=memWritten/totalMemory*100;
			float percentComplete = ((float)memWritten / (float) totalMemory) * (float) 100;
			uint32 sigBit = (uint32) percentComplete;
			//printf("Percent Complete - %d \n",intPercentCompete);
			//printf("Percent Complete - %f \n",percentComplete);
			
			if(sigBit==(uint32)compareBit){
				printf("\n Walking Ones Percent Complete - %d%% \n",sigBit);
				compareBit=compareBit+5;
			}		

			}
			

	
		printf("\n Walking Ones Test complete without errors \n");
		//pIo_Stream->Io_StreamPutLine("Walking Ones Test complete without errors");
		WriteAllDDROne();
		compareBit =0;
		for(memAddress=DDR_START_ADDR; memAddress<DDR_END_ADDR+1; memAddress+=4) {
			
			dataWrite = 0x7FFFFFFF;
			
			for (uint16 bit=0;bit<=31;bit++) {
				WRITEMEM32(memAddress, dataWrite); 
				dataRead = READMEM32(memAddress);
				if(dataRead!=dataWrite) {
					pIo_Stream->Io_StreamPutLine("Walking Zeros failed at memory location");
					printf("Walking Zeros failed at memory location %X", memAddress);
					break;
				}
				else {
				}
				//dataWrite=dataWrite<<1;
				
				//rotate right
				dataWrite = (dataWrite >> 1) | (dataWrite << (32 - 1));
				
			}
			WRITEMEM32(memAddress, 0xFFFFFFFF);
			uint32 totalMemory	= (uint32) DDR_END_ADDR - (uint32) DDR_START_ADDR;
			uint32 memWritten = (uint32) memAddress - (uint32) DDR_START_ADDR;
//			uint32 intPercentCompete=memWritten/totalMemory*100;
			float percentComplete = ((float)memWritten / (float) totalMemory) * (float) 100;
			uint32 sigBit = (uint32) percentComplete;
			//printf("Percent Complete - %d \n",intPercentCompete);
			//printf("Percent Complete - %f \n",percentComplete);
			
			if(sigBit==(uint32)compareBit){
				printf("\n Walking Zeros Percent Complete - %d%% \n",sigBit);
				compareBit=compareBit+5;
			}			
		}
		pIo_Stream->Io_StreamPutLine("Walking Zeros Test complete without errors");				
		// format and copy the response
		//std::stringstream myOstream(rResponseText);
		//myOstream << dec << TEST_CASE_ID_DDR_WRITE << hex << memData;
		sprintf(responseBuffer, "%d %X",TEST_CASE_ID_DDR_WALKING_ONES,memData);
		rResponseText = responseBuffer;
	}
	// too few or too many parameters
	else
	{
		rResponseText = "-03";
	}
	return;
}

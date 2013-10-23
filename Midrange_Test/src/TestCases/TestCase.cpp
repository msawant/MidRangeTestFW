#include "TestCase.hpp"
#include "utils/Io_Stream.hpp"
#include "drivers/moduleid.h"

// class constructor
TestCase::TestCase
(
	const int16 CommandNumber
)
: m_CommandNumber(CommandNumber)
{
}

// class destructor
TestCase::~TestCase()
{
}

void TestCase::EraseDDR(uint32 memStartEraseAddress, uint32 memEndEraseAddress)
{
		for(uint32 memAddress=memStartEraseAddress;memAddress<memEndEraseAddress;memAddress++) {
			WRITEMEM32(memAddress, 0x00000000);}
}

void TestCase::WriteAllDDRZero(void)
{	Io_Stream* pIo_Stream = new Io_Stream();
	 uint32 compareBit = 0;
		for(uint32 memAddress=DDR_START_ADDR;memAddress<=DDR_END_ADDR;memAddress++) {
			//printf("Writing Zeros to memory location %X \n", memAddress);
			WRITEMEM32(memAddress, 0x0000000);
			
			uint32 totalMemory	= (uint32) DDR_END_ADDR - (uint32) DDR_START_ADDR;
			uint32 memWritten = (uint32) memAddress - (uint32) DDR_START_ADDR;
//			uint32 intPercentCompete=memWritten/totalMemory*100;
			float percentComplete = ((float)memWritten / (float) totalMemory) * (float) 100;
			uint32 sigBit = (uint32) percentComplete;
			//printf("Percent Complete - %d \n",intPercentCompete);
			//printf("Percent Complete - %f \n",percentComplete);
			if(sigBit==(uint32)compareBit){
				printf("\n Writing Zeros Percent Complete - %d%% \n",sigBit);
				compareBit=compareBit+5;
			}
		}
		
	pIo_Stream->Io_StreamPutLine("Writing background Zeros complete");
}		
void TestCase::WriteAllDDROne(void)
{	uint32 compareBit = 0;
	Io_Stream* pIo_Stream = new Io_Stream();
		for(uint32 memAddress=DDR_START_ADDR;memAddress<=DDR_END_ADDR;memAddress++) {
			//printf("Writing Ones to memory location %X \n", memAddress);
			WRITEMEM32(memAddress, 0xFFFFFFFF);
			
			uint32 totalMemory	= (uint32) DDR_END_ADDR - (uint32) DDR_START_ADDR;
			uint32 memWritten = (uint32) memAddress - (uint32) DDR_START_ADDR;
//			uint32 intPercentCompete=memWritten/totalMemory*100;
			float percentComplete = ((float)memWritten / (float) totalMemory) * (float) 100;
			uint32 sigBit = (uint32) percentComplete;
			//printf("Percent Complete - %d \n",intPercentCompete);
			//printf("Percent Complete - %f \n",percentComplete);
			if(sigBit==(uint32)compareBit){
				printf("\n Writing Ones Percent Complete - %d%% \n",sigBit);
				compareBit=compareBit+5;
			}
		}
	printf("\nWriting background Ones complete\n");
	//pIo_Stream->Io_StreamPutLine("Writing background Ones complete");
}

#include "NANDWriteCommandTestCase.hpp"
#include <ti/pspiom/cslr/cslr.h>
#include <ti/pspiom/cslr/soc_OMAPL138.h>
#include <ti/pspiom/cslr/cslr_emifa2.h>

#include <stdio.h>

CSL_EmifaRegsOvly   emifRegs  = (CSL_EmifaRegsOvly)(CSL_EMIFA_0_REGS);
uint32 command = NAND_MEM_COMMAND;
uint32 address = NAND_ADD;
uint32 memReadAddress = 0x62000000;
uint8  comREADID  = 0x90;
uint8  memDEVID	  = 0x00;
uint8  memONFIID  = 0x20;	
uint8  nandRESET  = 0xFF;
uint8  nandSTATUS = 0x70;

//uint32 memData = 0;
uint32 memWrittenData=0;
uint8  memWrittenData8=0;	

// class constructor
NANDWriteCommandTestCase::NANDWriteCommandTestCase() 
: TestCase(TEST_CASE_ID_NAND_COMMAND_WRITE)
{
	// do nothing
}

// class destructor
NANDWriteCommandTestCase::~NANDWriteCommandTestCase()
{
}

void NANDWriteCommandTestCase::NANDBusy(){
	volatile uint32 temp;
	temp = (emifRegs->NANDFSR && CSL_EMIFA_NANDFSR_WAITST_MASK) >> CSL_EMIFA_NANDFSR_WAITST_SHIFT;
	while(!temp){
		//do nothing
		temp = (emifRegs->NANDFSR && CSL_EMIFA_NANDFSR_WAITST_MASK) >> CSL_EMIFA_NANDFSR_WAITST_SHIFT;
//		printf("polling %X\n",temp);
	}
}

void NANDWriteCommandTestCase::NANDReset(){
//	WRITEMEM8(command, nandSTATUS);
//	memWrittenData = READMEM8(memReadAddress);
//	printf("Nand Test current NAND status register value %x \n", memWrittenData);			
	WRITEMEM8(command, nandRESET);
}

void NANDWriteCommandTestCase::NANDReadStatusReg(){
	WRITEMEM8(command, nandSTATUS);
	memWrittenData = READMEM8(memReadAddress);
	printf("Nand Test current NAND status register value %x \n", memWrittenData);
}

void NANDWriteCommandTestCase::NANDReadManID(){
	printf("Nand Test reading Manufacturing Data");
	WRITEMEM8(command, comREADID);
	WRITEMEM8(address, memDEVID);
	memWrittenData8 = READMEM8(memReadAddress);
//	printf("Nand Test READID. Read a value of %x \n", memWrittenData8);
	memWrittenData8 = READMEM8(memReadAddress);
//	printf("Nand Test READID. Read a value of %x \n", memWrittenData8);
	memWrittenData8 = READMEM8(memReadAddress);
//	printf("Nand Test READID. Read a value of %x \n", memWrittenData8);
	memWrittenData8 = READMEM8(memReadAddress);
//	printf("Nand Test READID. Read a value of %x \n", memWrittenData8);
	memWrittenData8 = READMEM8(memReadAddress);
//	printf("Nand Test READID. Read a value of %x \n", memWrittenData8);
}

void NANDWriteCommandTestCase::NANDReadOnfiID(){
	WRITEMEM8(command, comREADID);
	WRITEMEM8(address, memONFIID);
	memWrittenData = READMEM32(memReadAddress);
	printf("Nand Test READONFIID. Read a value of %x \n", memWrittenData);
}

/////////////////////////////////////////////////////////////////////////////
// The DDR Write test case reads the memory data at the address passed in   //
// the second argument.  A successful read will return the test case       //
// number followed by the memory data in the rResponseText string.         //
/////////////////////////////////////////////////////////////////////////////
void NANDWriteCommandTestCase::Run
(
	int16 Argc, 				// number of arguments
	std::string* Argv,			// pointer to array variable argument 
	std::string &rResponseText	// reference string to place the response text 
)
{
	// Check to make sure the correct number of arguments was passed in for
	// this test case.
	if (Argc == NAND_WRITE_COMMAND_REQUIRED_ARGS)
	{

		char responseBuffer[32];
		
		
		NANDReset();
		//NANDBusy();
		//NANDReadStatusReg();
		
		//reading Manufacturing data as 8 bit read cycles
		NANDReadManID();
		
		
		//reading Onfi ID using 32 bit read cycles
		NANDReadOnfiID();
		rResponseText = responseBuffer;
	}
	// too few or too many parameters
	else
	{
		rResponseText = "-03";
	}
	return;
}

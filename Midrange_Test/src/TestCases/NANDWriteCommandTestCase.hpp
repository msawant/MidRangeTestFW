#ifndef NANDWRITECOMMANDTESTCASE_HPP_
#define NANDWRITECOMMANDTESTCASE_HPP_

#include "TestCase.hpp"
#include <ti/pspiom/cslr/cslr.h>
#include <ti/pspiom/cslr/soc_OMAPL138.h>
#include <ti/pspiom/cslr/cslr_emifa2.h>

#ifndef NAND_MEM_BASE
#define NAND_MEM_BASE			(0x62000000)
#endif

#ifndef NAND_MEM_COMMAND
#define NAND_MEM_COMMAND		(0x62000010)
#endif

#ifndef NAND_ADD
#define NAND_ADD				(0x62000008)
#endif
// some handy macros for reading/writing to memory
#define READMEM8(pMem) 			(*(volatile uint8*)(pMem))
#define WRITEMEM8(pMem, data) 	((*(volatile uint8*)(pMem)) = data)

// define the test case ID number
#define TEST_CASE_ID_NAND_COMMAND_WRITE	(24)

class NANDWriteCommandTestCase : public TestCase
{
public:
	// Public constructor
	NANDWriteCommandTestCase();
	
	// destructor
	virtual ~NANDWriteCommandTestCase();
	
	void NANDReset();
	void NANDBusy();
	void NANDReadStatusReg();
	void NANDReadManID();	
	void NANDReadOnfiID();
	
	// run method for the test case
	virtual void Run
	(
		int16 Argc, 
		std::string* Argv,
		std::string &rResponseText
	);
	
	
private:
	enum NAND_Write_Command_Arguments
	{
		NAND_WRITE_COMMAND_ARG_COMMAND_NUM		= 0,
		//NAND_WRITE_COMMAND_ARG_WRITE_ADDRESS	= 1,
		//NAND_WRITE_COMMAND_ARG_WRITE_DATA		= 2,
		//NAND_WRITE_COMMAND_REQUIRED_ARGS		= 3
		NAND_WRITE_COMMAND_REQUIRED_ARGS		= 1
	};
};

#endif /*NANDWRITECOMMANDTESTCASE_HPP_*/

#ifndef NANDREADTESTCASE_HPP_
#define NANDREADTESTCASE_HPP_

#include "TestCase.hpp"

#define NAND_MEM_BASE			(0x0x62000000)
#define NAND_MEM_COMMAND		(0x0x62000010)
#define NAND_MEM_DATA			(0x0x62000008)
		
// some handy macros for reading/writing to memory
#define READMEM32(pMem) 		(*(volatile uint32*)(pMem))
#define WRITEMEM32(pMem, data) 	((*(volatile uint32*)(pMem)) = data)
#define READMEM8(pMem)			(*(volatile uint8*)(pMem))
// define the test case ID number
#define TEST_CASE_ID_NAND_READ	(11)

class NANDReadTestCase : public TestCase
{
public:
	// Public constructor
	NANDReadTestCase();
	
	// destructor
	virtual ~NANDReadTestCase();
	
	// run method for the test case
	virtual void Run
	(
		int16 Argc, 
		std::string* Argv,
		std::string &rResponseText
	);
	
	
private:
	enum NAND_Read_Arguments
	{
		NAND_READ_ARG_COMMAND_NUM	= 0,
		NAND_READ_ARG_READ_ADDRESS	= 1,
		NAND_READ_REQUIRED_ARGS		= 2
	};
};

#endif /*NANDREADTESTCASE_HPP_*/

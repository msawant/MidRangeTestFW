#ifndef DDRWRITEZEROSTESTCASE_HPP_
#define DDRWRITEZEROSTESTCASE_HPP_

#include "TestCase.hpp"

#define DDR_MEM_BASE			(0xC0000000)

// some handy macros for reading/writing to memory
#define READMEM32(pMem) 		(*(volatile uint32*)(pMem))
#define WRITEMEM32(pMem, data) 	((*(volatile uint32*)(pMem)) = data)

// define the test case ID number
#define TEST_CASE_ID_DDR_WRITE_ZEROS	(22)

class DDRWriteZerosTestCase : public TestCase
{
public:
	// Public constructor
	DDRWriteZerosTestCase();
	
	// destructor
	virtual ~DDRWriteZerosTestCase();
	
	// run method for the test case
	virtual void Run
	(
		int16 Argc, 
		std::string* Argv,
		std::string &rResponseText
	);
	
	
private:
	enum DDR_WalkingOnes_Arguments
	{
		DDR_WRITE_ZEROS_REQUIRED_ARG_COMMAND_NUM		= 0,
		//DDR_WALKING_ONES_REQUIRED_ARGS_START_ADDRESS	= 1,
		//DDR_WALKING_ONES_REQUIRED_ARGS_END_ADDRESS	= 2,
		DDR_WRITE_ZEROS_REQUIRED_ARGS					= 1
	};
};

#endif /*DDRWRITEZEROSTESTCASE_HPP_*/

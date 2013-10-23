#ifndef DDRWRITETESTCASE_HPP_
#define DDRWRITETESTCASE_HPP_

#include "TestCase.hpp"

#define DDR_MEM_BASE			(0xC0000000)

// some handy macros for reading/writing to memory
#define READMEM32(pMem) 		(*(volatile uint32*)(pMem))
#define WRITEMEM32(pMem, data) 	((*(volatile uint32*)(pMem)) = data)

// define the test case ID number
#define TEST_CASE_ID_DDR_WRITE	(20)

class DDRWriteTestCase : public TestCase
{
public:
	// Public constructor
	DDRWriteTestCase();
	
	// destructor
	virtual ~DDRWriteTestCase();
	
	// run method for the test case
	virtual void Run
	(
		int16 Argc, 
		std::string* Argv,
		std::string &rResponseText
	);
	
	
private:
	enum DDR_Write_Arguments
	{
		DDR_WRITE_ARG_COMMAND_NUM	= 0,
		DDR_WRITE_ARG_WRITE_ADDRESS	= 1,
		DDR_WRITE_ARG_WRITE_DATA	= 2,
		DDR_WRITE_REQUIRED_ARGS		= 3
	};
};

#endif /*DDRWRITETESTCASE_HPP_*/

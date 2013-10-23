#ifndef WRITE16TESTCASE_HPP_
#define WRITE16TESTCASE_HPP_

#include "TestCase.hpp"

#define DDR_MEM_BASE			(0xC0000000)

// some handy macros for reading/writing to memory
#define READMEM16(pMem) 		(*(volatile uint16*)(pMem))
#define WRITEMEM16(pMem, data) 	((*(volatile uint16*)(pMem)) = data)

// define the test case ID number
#define TEST_CASE_ID_16_WRITE	(17)

class Write16TestCase : public TestCase
{
public:
	// Public constructor
	Write16TestCase();
	
	// destructor
	virtual ~Write16TestCase();
	
	// run method for the test case
	virtual void Run
	(
		int16 Argc, 
		std::string* Argv,
		std::string &rResponseText
	);
	
	
private:
	enum Write_16_Arguments
	{
		WRITE_16_ARG_COMMAND_NUM	= 0,
		WRITE_16_ARG_WRITE_ADDRESS	= 1,
		WRITE_16_ARG_WRITE_DATA	= 2,
		WRITE_16_REQUIRED_ARGS		= 3
	};
};

#endif /*WRITE16TESTCASE_HPP_*/

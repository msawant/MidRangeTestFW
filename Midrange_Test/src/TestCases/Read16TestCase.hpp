#ifndef READ16TESTCASE_HPP_
#define READ16TESTCASE_HPP_

#include "TestCase.hpp"

//#define DDR_MEM_BASE			(0xC0000000)

// some handy macros for reading/writing to memory
#define READMEM16(pMem) 		(*(volatile uint16*)(pMem))
#define WRITEMEM16(pMem, data) 	((*(volatile uint16*)(pMem)) = data)
#define READMEM8(pMem) 		(*(volatile uint8*)(pMem))
#define WRITEMEM8(pMem, data) 	((*(volatile uint8*)(pMem)) = data)

// define the test case ID number
#define TEST_CASE_ID_16_READ	(16)

class Read16TestCase : public TestCase
{
public:
	// Public constructor
	Read16TestCase();
	
	// destructor
	virtual ~Read16TestCase();
	
	// run method for the test case
	virtual void Run
	(
		int16 Argc, 
		std::string* Argv,
		std::string &rResponseText
	);
	
	
private:
	enum Read_16_Arguments
	{
		READ_16__ARG_COMMAND_NUM	= 0,
		READ_16_ARG_READ_ADDRESS	= 1,
		READ_16_REQUIRED_ARGS		= 2
	};
};

#endif /*READ16TESTCASE_HPP_*/

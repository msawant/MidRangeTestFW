#ifndef DDRREADTESTCASE_HPP_
#define DDRREADTESTCASE_HPP_

#include "TestCase.hpp"

#define DDR_MEM_BASE			(0xC0000000)

// some handy macros for reading/writing to memory
#define READMEM32(pMem) 		(*(volatile uint32*)(pMem))
#define WRITEMEM32(pMem, data) 	((*(volatile uint32*)(pMem)) = data)

// define the test case ID number
#define TEST_CASE_ID_DDR_READ	(10)

class DDRReadTestCase : public TestCase
{
public:

	
	// Public constructor
	DDRReadTestCase();
	
	// destructor
	virtual ~DDRReadTestCase();
	
	// run method for the test case
	virtual void Run
	(
		int16 Argc, 
		std::string* Argv,
		std::string &rResponseText
	);
	
	
private:
	enum DDR_Read_Arguments
	{
		DDR_READ_ARG_COMMAND_NUM	= 0,
		DDR_READ_ARG_READ_ADDRESS	= 1,
		DDR_READ_REQUIRED_ARGS		= 2
	};
};

#endif /*DDRREADTESTCASE_HPP_*/

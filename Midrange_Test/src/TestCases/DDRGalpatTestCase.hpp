#ifndef DDRGALPATTESTCASE_HPP_
#define DDRGALPATTESTCASE_HPP_

#include "TestCase.hpp"

#define DDR_MEM_BASE			(0xC0000000)

// some handy macros for reading/writing to memory
#define READMEM32(pMem) 		(*(volatile uint32*)(pMem))
#define WRITEMEM32(pMem, data) 	((*(volatile uint32*)(pMem)) = data)

// define the test case ID number
#define TEST_CASE_ID_DDR_GALPAT		(100)

class DDRGalpatTestCase : public TestCase
{
public:
	// Public constructor
	DDRGalpatTestCase();
	
	// destructor
	virtual ~DDRGalpatTestCase();
	
	// run method for the test case
	virtual void Run
	(
		int16 Argc, 
		std::string* Argv,
		std::string &rResponseText
	);
	
	
private:
	enum DDR_Galpat_Arguments
	{
		DDR_GALPAT_REQUIRED_ARG_COMMAND_NUM		= 0,
		DDR_GALPAT_REQUIRED_ARGS_START_ADDRESS	= 1,
		DDR_GALPAT_REQUIRED_ARGS_END_ADDRESS	= 2,
		DDR_GALPAT_REQUIRED_ARGS				= 3
	};
};

#endif /*GALPATTESTCASE_HPP_*/

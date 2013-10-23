#ifndef GPIOTESTCASE_HPP_
#define GPIOTESTCASE_HPP_

#include "TestCase.hpp"
#include <stdio.h>
#include <ti/pspiom/cslr/cslr.h>
#include <ti/pspiom/cslr/soc_OMAPL138.h>
#include <ti/pspiom/cslr/cslr_gpio.h>

// define the test case ID number
#define TEST_CASE_ID_GPIO	(40)

class GPIOTestCase : public TestCase
{
public:
	// Public constructor
	GPIOTestCase();
	
	// destructor
	virtual ~GPIOTestCase();
	
	// run method for the test case
	virtual void Run
	(
		int16 Argc, 
		std::string* Argv,
		std::string &rResponseText
	);
	
	
private:
	enum GPIO_Arguments
	{
		GPIO_ARG_COMMAND_NUM	= 0,
		GPIO_ARG_GPIO_BANK		= 1,
		GPIO_ARG_GPIO_PIN		= 2,
		GPIO_ARG_GPIO_STATE		= 3,
		GPIO_REQUIRED_ARGS		= 4
	};
};

#endif /*GPIOTESTCASE_HPP_*/

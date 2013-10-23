#ifndef EEPROMTESTCASE_HPP_
#define EEPROMTESTCASE_HPP_

#include "TestCase.hpp"
#include <stdio.h>
#include <ti/pspiom/cslr/cslr.h>
#include <ti/pspiom/cslr/soc_OMAPL138.h>
#include <ti/pspiom/cslr/cslr_syscfg0_OMAPL138.h>
#include <ti/pspiom/cslr/cslr_i2c.h>

// define the test case ID number
#define TEST_CASE_ID_EEPROM	(50)



class EEPROMTestCase : public TestCase
{
public:
	// Public constructor
	EEPROMTestCase();
	
	// destructor
	virtual ~EEPROMTestCase();
	
	// run method for the test case
	virtual void Run
	(
		int16 Argc, 
		std::string* Argv,
		std::string &rResponseText
	);
	
	
private:
	enum EEPROM_Arguments
	{
		EEPROM_ARG_COMMAND_NUM	= 0,
		EEPROM_ARG_DATA	= 1,
		EEPROM_REQUIRED_ARGS	= 2
	};
};

#endif /*EEPROMTESTCASE_HPP_*/

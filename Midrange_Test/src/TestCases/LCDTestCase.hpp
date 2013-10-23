#ifndef LCDTESTCASE_HPP_
#define LCDTESTCASE_HPP_

#include "TestCase.hpp"
#include <stdio.h>
#include <ti/pspiom/cslr/cslr.h>
#include <ti/pspiom/cslr/soc_OMAPL138.h>
#include <ti/pspiom/cslr/cslr_gpio.h>

// define the test case ID number
#define TEST_CASE_ID_LCD	(50)

void clr_gpio(int,int);
void set_gpio(int,int);
void set_value(int);
void set_ev(int);
void insert_delay(Uint32);

void display_image();
void set_data(int);
void pixels_off();
void pixels_on();
void clear_image();
void display_smiley();
Uint16 read_status();

class LCDTestCase : public TestCase
{
public:
	// Public constructor
	LCDTestCase();
	
	// destructor
	virtual ~LCDTestCase();
	
	// run method for the test case
	virtual void Run
	(
		int16 Argc, 
		std::string* Argv,
		std::string &rResponseText
	);
	
	
private:
	enum LCD_Arguments
	{
		LCD_ARG_COMMAND_NUM	      = 0,
		LCD_ARG_COMMAND_NUMBER	  = 1,
		LCD_ARG_VALUE     		  = 2,
		LCD_REQUIRED_ARGS		  = 3
	};
};

#endif /*LCDTESTCASE_HPP_*/

#include "EEPROMTestCase.hpp"

#include <stdio.h>
#include <ti/pspiom/cslr/cslr.h>
#include <ti/pspiom/cslr/soc_OMAPL138.h>
#include <ti/pspiom/cslr/cslr_i2c.h>

CSL_I2cRegsOvly I2cRegs = (CSL_I2cRegsOvly)CSL_MDIO_0_REGS ;
int EEPROM_PHY_ADDR = 0x01;

//Indication of if I2C instance exists
unit8 s_IsInitInstance0 = 0;

//Method to initialize I2C Master
uint8 I2C_InitEEPROM();	

// class constructor
EEPROMTestCase::EEPROMTestCase() 
: TestCase(TEST_CASE_ID_EEPROM)
{
	// do nothing
}

// class destructor
EEPROMTestCase::~EEPROMTestCase()
{
}

/////////////////////////////////////////////////////////////////////////////
// The DDR Write test case reads the memory data at the address passed in   //
// the second argument.  A successful read will return the test case       //
// number followed by the memory data in the rResponseText string.         //
/////////////////////////////////////////////////////////////////////////////
void EEPROMTestCase::Run
(
	int16 Argc, 				// number of arguments
	std::string* Argv,			// pointer to array variable argument 
	std::string &rResponseText	// reference string to place the response text 
)
{
	
	
	//CSL_FINST(MDIO_REGS->, PER_REG_FIELD, TOKEN)
//	// Check to make sure the correct number of arguments was passed in for
//	// this test case.
	if (Argc == EEPROM_REQUIRED_ARGS)
	{

		sscanf(Argv[1].c_str(),"%X",data);
		
		sprintf(responseBuffer, "%d %X",TEST_CASE_ID_PHY,data);
		rResponseText = responseBuffer;
	}
//	// too few or too many parameters
	else
	{
		rResponseText = "-03";
	}
	return;
}


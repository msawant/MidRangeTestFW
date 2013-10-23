#include "GPIOTestCase.hpp"

#include <stdio.h>
#include <ti/pspiom/cslr/cslr.h>
#include <ti/pspiom/cslr/soc_OMAPL138.h>
#include <ti/pspiom/cslr/cslr_gpio.h>
#include <ti/pspiom/cslr/cslr_syscfg1_OMAPL138.h>
#include <ti/pspiom/cslr/cslr_psc_OMAPL138.h>

CSL_Syscfg1RegsOvly   sysRegs  = (CSL_Syscfg1RegsOvly)(CSL_SYSCFG_0_REGS);
CSL_PscRegsOvly      psc1Regs = (CSL_PscRegsOvly)(CSL_PSC_1_REGS);
CSL_GpioRegsOvly     gpioRegs = (CSL_GpioRegsOvly)(CSL_GPIO_0_REGS);

// class constructor
GPIOTestCase::GPIOTestCase() 
: TestCase(TEST_CASE_ID_GPIO)
{
	// do nothing
}

// class destructor
GPIOTestCase::~GPIOTestCase()
{
}

/////////////////////////////////////////////////////////////////////////////
// The DDR Write test case reads the memory data at the address passed in   //
// the second argument.  A successful read will return the test case       //
// number followed by the memory data in the rResponseText string.         //
/////////////////////////////////////////////////////////////////////////////
void GPIOTestCase::Run
(
	int16 Argc, 				// number of arguments
	std::string* Argv,			// pointer to array variable argument 
	std::string &rResponseText	// reference string to place the response text 
)
{

 
  
	//CSL_FINST(MDIO_REGS->, PER_REG_FIELD, TOKEN)
//	// Check to make sure the correct number of arguments was passed in for
//	// this test case.
	if (Argc == GPIO_REQUIRED_ARGS)
	{
		char responseBuffer[32];
		volatile Uint32 temp = 0;
		int gpio_bank = 10;
		int gpio_pin = 20;
		int BANK=10;
		int state = 5;
		volatile Uint32 pscTimeoutCount = 10240u;
		volatile Uint16 CSL_GPIO_SET_DATA_SET_MASK = 0;
		volatile Uint16 CSL_GPIO_SET_DATA_SET_SHIFT = 0;
		volatile Uint16 CSL_GPIO_DIR_DIR_SHIFT = 0;
		volatile Uint16 CSL_GPIO_CLR_DATA_CLR_MASK = 0;
		volatile Uint16 CSL_GPIO_CLR_DATA_CLR_SHIFT = 0;

		sscanf(Argv[1].c_str(),"%d",&gpio_bank);
		sscanf(Argv[2].c_str(),"%d",&gpio_pin);
		sscanf(Argv[3].c_str(),"%d",&state);
		
		switch (gpio_bank)
		{
			case 0:
			BANK = GP0;
			break;
			
			case 1:
			BANK = GP1;
			break;
			
			case 2:
			BANK = GP2;
			break;
			
			case 3:
			BANK = GP3;
			break;
			
			case 4:
			BANK = GP4;
			break;
			
			case 5:
			BANK = GP5;
			break;
			
			case 6:
			BANK = GP6;
			break;
			
			case 7:
			BANK = GP7;
			break;
			
			case 8:
			BANK = GP8;
			break;
			
			default:
			BANK=NULL;
			break;
		}
		
		switch (gpio_pin)
		{
			case 0:
			CSL_GPIO_SET_DATA_SET_MASK = CSL_GPIO_SET_DATA_SET0_MASK;
			CSL_GPIO_SET_DATA_SET_SHIFT = CSL_GPIO_SET_DATA_SET0_SHIFT;
			CSL_GPIO_DIR_DIR_SHIFT = CSL_GPIO_DIR_DIR0_SHIFT;
			CSL_GPIO_CLR_DATA_CLR_MASK = CSL_GPIO_CLR_DATA_CLR0_MASK;
			CSL_GPIO_CLR_DATA_CLR_SHIFT = CSL_GPIO_CLR_DATA_CLR0_SHIFT;
			break;
			
			case 1:
			CSL_GPIO_SET_DATA_SET_MASK = CSL_GPIO_SET_DATA_SET1_MASK;
			CSL_GPIO_SET_DATA_SET_SHIFT = CSL_GPIO_SET_DATA_SET1_SHIFT;
			CSL_GPIO_DIR_DIR_SHIFT = CSL_GPIO_DIR_DIR0_SHIFT;
			CSL_GPIO_CLR_DATA_CLR_MASK = CSL_GPIO_CLR_DATA_CLR1_MASK;
			CSL_GPIO_CLR_DATA_CLR_SHIFT = CSL_GPIO_CLR_DATA_CLR1_SHIFT;
			break;
			
			case 2:
			CSL_GPIO_SET_DATA_SET_MASK = CSL_GPIO_SET_DATA_SET2_MASK;
			CSL_GPIO_SET_DATA_SET_SHIFT = CSL_GPIO_SET_DATA_SET2_SHIFT;
			CSL_GPIO_DIR_DIR_SHIFT = CSL_GPIO_DIR_DIR2_SHIFT;
			CSL_GPIO_CLR_DATA_CLR_MASK = CSL_GPIO_CLR_DATA_CLR2_MASK;
			CSL_GPIO_CLR_DATA_CLR_SHIFT = CSL_GPIO_CLR_DATA_CLR2_SHIFT;
			break;
			
			case 3:
			CSL_GPIO_SET_DATA_SET_MASK = CSL_GPIO_SET_DATA_SET3_MASK;
			CSL_GPIO_SET_DATA_SET_SHIFT = CSL_GPIO_SET_DATA_SET3_SHIFT;
			CSL_GPIO_DIR_DIR_SHIFT = CSL_GPIO_DIR_DIR3_SHIFT;
			CSL_GPIO_CLR_DATA_CLR_MASK = CSL_GPIO_CLR_DATA_CLR3_MASK;
			CSL_GPIO_CLR_DATA_CLR_SHIFT = CSL_GPIO_CLR_DATA_CLR3_SHIFT;
			break;
			
			case 4:
			CSL_GPIO_SET_DATA_SET_MASK = CSL_GPIO_SET_DATA_SET4_MASK;
			CSL_GPIO_SET_DATA_SET_SHIFT = CSL_GPIO_SET_DATA_SET4_SHIFT;
			CSL_GPIO_DIR_DIR_SHIFT = CSL_GPIO_DIR_DIR4_SHIFT;
			CSL_GPIO_CLR_DATA_CLR_MASK = CSL_GPIO_CLR_DATA_CLR4_MASK;
			CSL_GPIO_CLR_DATA_CLR_SHIFT = CSL_GPIO_CLR_DATA_CLR4_SHIFT;
			break;
			
			case 5:
			CSL_GPIO_SET_DATA_SET_MASK = CSL_GPIO_SET_DATA_SET5_MASK;
			CSL_GPIO_SET_DATA_SET_SHIFT = CSL_GPIO_SET_DATA_SET5_SHIFT;
			CSL_GPIO_DIR_DIR_SHIFT = CSL_GPIO_DIR_DIR5_SHIFT;
			CSL_GPIO_CLR_DATA_CLR_MASK = CSL_GPIO_CLR_DATA_CLR5_MASK;
			CSL_GPIO_CLR_DATA_CLR_SHIFT = CSL_GPIO_CLR_DATA_CLR5_SHIFT;
			break;
			
			case 6:
			CSL_GPIO_SET_DATA_SET_MASK = CSL_GPIO_SET_DATA_SET6_MASK;
			CSL_GPIO_SET_DATA_SET_SHIFT = CSL_GPIO_SET_DATA_SET6_SHIFT;
			CSL_GPIO_DIR_DIR_SHIFT = CSL_GPIO_DIR_DIR6_SHIFT;
			CSL_GPIO_CLR_DATA_CLR_MASK = CSL_GPIO_CLR_DATA_CLR6_MASK;
			CSL_GPIO_CLR_DATA_CLR_SHIFT = CSL_GPIO_CLR_DATA_CLR6_SHIFT;
			break;
			
			case 7:
			CSL_GPIO_SET_DATA_SET_MASK = CSL_GPIO_SET_DATA_SET7_MASK;
			CSL_GPIO_SET_DATA_SET_SHIFT = CSL_GPIO_SET_DATA_SET7_SHIFT;
			CSL_GPIO_DIR_DIR_SHIFT = CSL_GPIO_DIR_DIR7_SHIFT;
			CSL_GPIO_CLR_DATA_CLR_MASK = CSL_GPIO_CLR_DATA_CLR7_MASK;
			CSL_GPIO_CLR_DATA_CLR_SHIFT = CSL_GPIO_CLR_DATA_CLR7_SHIFT;
			break;
			
			case 8:
			CSL_GPIO_SET_DATA_SET_MASK = CSL_GPIO_SET_DATA_SET8_MASK;
			CSL_GPIO_SET_DATA_SET_SHIFT = CSL_GPIO_SET_DATA_SET8_SHIFT;
			CSL_GPIO_DIR_DIR_SHIFT = CSL_GPIO_DIR_DIR8_SHIFT;
			CSL_GPIO_CLR_DATA_CLR_MASK = CSL_GPIO_CLR_DATA_CLR8_MASK;
			CSL_GPIO_CLR_DATA_CLR_SHIFT = CSL_GPIO_CLR_DATA_CLR8_SHIFT;
			break;
			
			case 9:
			CSL_GPIO_SET_DATA_SET_MASK = CSL_GPIO_SET_DATA_SET9_MASK;
			CSL_GPIO_SET_DATA_SET_SHIFT = CSL_GPIO_SET_DATA_SET9_SHIFT;
			CSL_GPIO_DIR_DIR_SHIFT = CSL_GPIO_DIR_DIR9_SHIFT;
			CSL_GPIO_CLR_DATA_CLR_MASK = CSL_GPIO_CLR_DATA_CLR9_MASK;
			CSL_GPIO_CLR_DATA_CLR_SHIFT = CSL_GPIO_CLR_DATA_CLR9_SHIFT;
			break;
			
			case 10:
			CSL_GPIO_SET_DATA_SET_MASK = CSL_GPIO_SET_DATA_SET10_MASK;
			CSL_GPIO_SET_DATA_SET_SHIFT = CSL_GPIO_SET_DATA_SET10_SHIFT;
			CSL_GPIO_DIR_DIR_SHIFT = CSL_GPIO_DIR_DIR10_SHIFT;
			CSL_GPIO_CLR_DATA_CLR_MASK = CSL_GPIO_CLR_DATA_CLR10_MASK;
			CSL_GPIO_CLR_DATA_CLR_SHIFT = CSL_GPIO_CLR_DATA_CLR10_SHIFT;
			break;
			
			case 11:
			CSL_GPIO_SET_DATA_SET_MASK = CSL_GPIO_SET_DATA_SET11_MASK;
			CSL_GPIO_SET_DATA_SET_SHIFT = CSL_GPIO_SET_DATA_SET11_SHIFT;
			CSL_GPIO_DIR_DIR_SHIFT = CSL_GPIO_DIR_DIR11_SHIFT;
			CSL_GPIO_CLR_DATA_CLR_MASK = CSL_GPIO_CLR_DATA_CLR11_MASK;
			CSL_GPIO_CLR_DATA_CLR_SHIFT = CSL_GPIO_CLR_DATA_CLR11_SHIFT;
			break;
			
			case 12:
			CSL_GPIO_SET_DATA_SET_MASK = CSL_GPIO_SET_DATA_SET12_MASK;
			CSL_GPIO_SET_DATA_SET_SHIFT = CSL_GPIO_SET_DATA_SET12_SHIFT;
			CSL_GPIO_DIR_DIR_SHIFT = CSL_GPIO_DIR_DIR12_SHIFT;
			CSL_GPIO_CLR_DATA_CLR_MASK = CSL_GPIO_CLR_DATA_CLR12_MASK;
			CSL_GPIO_CLR_DATA_CLR_SHIFT = CSL_GPIO_CLR_DATA_CLR12_SHIFT;
			break;
			
			case 13:
			CSL_GPIO_SET_DATA_SET_MASK = CSL_GPIO_SET_DATA_SET13_MASK;
			CSL_GPIO_SET_DATA_SET_SHIFT = CSL_GPIO_SET_DATA_SET13_SHIFT;
			CSL_GPIO_DIR_DIR_SHIFT = CSL_GPIO_DIR_DIR13_SHIFT;
			CSL_GPIO_CLR_DATA_CLR_MASK = CSL_GPIO_CLR_DATA_CLR13_MASK;
			CSL_GPIO_CLR_DATA_CLR_SHIFT = CSL_GPIO_CLR_DATA_CLR13_SHIFT;
			break;
		
			case 14:
			CSL_GPIO_SET_DATA_SET_MASK = CSL_GPIO_SET_DATA_SET14_MASK;
			CSL_GPIO_SET_DATA_SET_SHIFT = CSL_GPIO_SET_DATA_SET14_SHIFT;
			CSL_GPIO_DIR_DIR_SHIFT = CSL_GPIO_DIR_DIR14_SHIFT;
			CSL_GPIO_CLR_DATA_CLR_MASK = CSL_GPIO_CLR_DATA_CLR14_MASK;
			CSL_GPIO_CLR_DATA_CLR_SHIFT = CSL_GPIO_CLR_DATA_CLR14_SHIFT;
			break;
			
			case 15:
			CSL_GPIO_SET_DATA_SET_MASK = CSL_GPIO_SET_DATA_SET15_MASK;
			CSL_GPIO_SET_DATA_SET_SHIFT = CSL_GPIO_SET_DATA_SET15_SHIFT;
			CSL_GPIO_DIR_DIR_SHIFT = CSL_GPIO_DIR_DIR15_SHIFT;
			CSL_GPIO_CLR_DATA_CLR_MASK = CSL_GPIO_CLR_DATA_CLR15_MASK;
			CSL_GPIO_CLR_DATA_CLR_SHIFT = CSL_GPIO_CLR_DATA_CLR15_SHIFT;
			break;
		}


		
		
		if(state==1){
			//gpioRegs->BANK[BANK].DIR &= ~(CSL_GPIO_DIR_DIR_OUT <<  CSL_GPIO_DIR_DIR_SHIFT);
			temp = 	( (temp & CSL_GPIO_SET_DATA_SET_MASK) |	(CSL_GPIO_SET_DATA_SET_SET << CSL_GPIO_SET_DATA_SET_SHIFT));
			gpioRegs->BANK[BANK].SET_DATA |= temp;
			printf ("GPIO %d_%d been set high \n", gpio_bank, gpio_pin);
			
		}
		else if (state == 0){
			//temp = gpioRegs->BANK[BANK].CLR_DATA;
			//gpioRegs->BANK[BANK].DIR &= ~(CSL_GPIO_DIR_DIR_OUT <<  CSL_GPIO_DIR_DIR_SHIFT);
			temp = ( (temp & CSL_GPIO_CLR_DATA_CLR_MASK) |  (CSL_GPIO_CLR_DATA_CLR_CLR << CSL_GPIO_CLR_DATA_CLR_SHIFT) );
            gpioRegs->BANK[BANK].CLR_DATA &= temp;
        	printf ("GPIO %d_%d been set low \n", gpio_bank, gpio_pin);
		}
		else{
			sprintf(responseBuffer, "\n%d %s",TEST_CASE_ID_GPIO,"Entered Default Case\n");
		}
		
		sprintf(responseBuffer, "\n%d %s",TEST_CASE_ID_GPIO,"GPIO Toggle Done\n");

		rResponseText = responseBuffer;
	}
//	// too few or too many parameters
	else
	{
		rResponseText = "-03";
	}
	return;
} 



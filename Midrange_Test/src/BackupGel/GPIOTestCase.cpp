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

static void delay(Uint32 count);

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
		int gpio = 10;
		int BANK=10;
		int state = 5;
		volatile Uint32 pscTimeoutCount = 10240u;
//	
//    volatile Uint32 pscTimeoutCount = 10240u;
//    CSL_Psc1Peripheral GPIO_LPSC_NUM = CSL_PSC_GPIO;
//	 /* Bring the GPIO module out of sleep state                                 */
//  /* Configure the GPIO Module to Enable state */
//   psc1Regs->MDCTL[GPIO_LPSC_NUM] =
//                              ( (psc1Regs->MDCTL[GPIO_LPSC_NUM] & 0xFFFFFFE0) | \
//                                 CSL_PSC_MDSTAT_STATE_ENABLE );
//  /* Kick start the Enable Command */
//  temp = psc1Regs->PTCMD;
//  temp = ( (temp & CSL_PSC_PTCMD_GO0_MASK) |
//           (CSL_PSC_PTCMD_GO0_SET << CSL_PSC_PTCMD_GO0_SHIFT) );
//  psc1Regs->PTCMD |= temp;
//  /*Wait for the power state transition to occur */
//  while ( ((psc1Regs->PTSTAT & (CSL_PSC_PTSTAT_GOSTAT0_IN_TRANSITION)) != 0)
//                     && (pscTimeoutCount>0) )
//  {
//      pscTimeoutCount--;
//  }
//  /* Check if PSC state transition timed out */
//  if(pscTimeoutCount == 0)
//  {
//      printf("GPIO PSC transition to ON state timed out\n");
//      return;
//  }
//  /* Wait for MODSTAT = ENABLE/DISABLE from LPSC */
//  pscTimeoutCount = 10240u;
//  while( ((psc1Regs->MDSTAT[GPIO_LPSC_NUM] & (CSL_PSC_MDSTAT_STATE_MASK))
//                != CSL_PSC_MDSTAT_STATE_ENABLE) && (pscTimeoutCount>0))
//  {
//      pscTimeoutCount--;
//  }
//  /* If timeout, the resource may not be functioning */
//  if (0 == pscTimeoutCount)
//   {
//     printf("GPIO Module Enable timed out\n");
//     return;
//  }
//  /* Configure GPIO4_0 (GPIO4_0_PIN) as an output */
// gpioRegs->BANK[GP4].DIR &= ~(CSL_GPIO_DIR_DIR_IN << CSL_GPIO_DIR_DIR0_SHIFT);
//  /* Set Data high in SET_DATA register for GPIO(GPIO4_0_PIN).                *
//   * This turns the LED off -see schematic                                    */
//  temp = gpioRegs->BANK[GP4].SET_DATA;
//  temp = ( (temp & CSL_GPIO_SET_DATA_SET0_MASK) |
//            (CSL_GPIO_SET_DATA_SET_SET << CSL_GPIO_SET_DATA_SET0_SHIFT));
//  gpioRegs->BANK[GP4].SET_DATA |= temp;
//  
//		//configure bank 4 as output
//		 gpioRegs->BANK[GP4].DIR &= ~(CSL_GPIO_DIR_DIR_OUT << CSL_GPIO_DIR_DIR0_SHIFT);
//*/		 
		sscanf(Argv[1].c_str(),"%d",&gpio);
		
		sscanf(Argv[1].c_str(),"%d",&state);
		
		switch (gpio)
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


		
		
		if(state==1){
			temp = 	( (temp & CSL_GPIO_SET_DATA_SET0_MASK) |
			(CSL_GPIO_SET_DATA_SET_SET << CSL_GPIO_SET_DATA_SET0_SHIFT));
			gpioRegs->BANK[GP4].SET_DATA |= temp;
			sprintf(responseBuffer, "%d %s",TEST_CASE_ID_GPIO,"DSL High");
		}
		else if (state ==0){
			temp = gpioRegs->BANK[GP4].CLR_DATA;
			gpioRegs->BANK[GP4].DIR &= ~(CSL_GPIO_DIR_DIR_OUT <<  CSL_GPIO_DIR_DIR0_SHIFT);
			temp = ( (temp & CSL_GPIO_CLR_DATA_CLR0_MASK) |
             (CSL_GPIO_CLR_DATA_CLR_CLR << CSL_GPIO_CLR_DATA_CLR0_SHIFT) );
            gpioRegs->BANK[GP4].CLR_DATA |= temp;
        	sprintf(responseBuffer, "\n%d %s",TEST_CASE_ID_GPIO,"DSL Low\n");
		}
		else{
			sprintf(responseBuffer, "\n%d %s",TEST_CASE_ID_GPIO,"Entered Default Case\n");
		}
		
		sprintf(responseBuffer, "\n%d %s",TEST_CASE_ID_GPIO,"DSL Reset Done\n");
		//sprintf(responseBuffer, "%d %X",TEST_CASE_ID_PHY,data);
		rResponseText = responseBuffer;
	}
//	// too few or too many parameters
	else
	{
		rResponseText = "-03";
	}
	return;
} 

static void delay(Uint32 count)
{
    volatile Uint32 tempCount = 0;
    volatile Uint32 dummyCount = 0;
    for (tempCount = 0; tempCount < count; tempCount++)
    {
        for (dummyCount = 0; dummyCount < count; dummyCount++)
        {
            /* dummy loop to wait for some time  */
        }
    }
}

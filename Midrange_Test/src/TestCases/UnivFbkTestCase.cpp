#include "UnivFbkTestCase.hpp"
#include "drivers/univ_fbk_uart.h"
#include "drivers/adc7866.h"
#include "drivers/timekeeper.h"
//Base Class Constructor
//Constructor
UnivFbkTestCase::UnivFbkTestCase()
:TestCase(TEST_CASE_ID_UNIV_FBK_TEST){
 //do nothing	
}

UnivFbkTestCase::~UnivFbkTestCase(){
	//do nothing
}


void UnivFbkTestCase::Run(
int16 Argc,					// number of arguments
std::string* Argv,			// pointer to array variable argument
std::string &rResponseText	// reference string to place the response text
)

{
	// Check to make sure the correct number of arguments was passed in for
	// this test case.
	if (Argc >= UNIV_FBK_REQUIRED_ARGS && Argc <= UNIV_FBK_MAX_ARGS)
	{	uint16 code = 0;
		int subArg = 0;
		char *blank="";
		int bytes = 0;
		int i;
		volatile int test;
		int timer;
		univ_fbk_uart_init_default();
		char responseBuffer[200];
		sscanf(Argv[1].c_str(),"%d",&code);
		SetPseudoTimePeriodUSec(0x0010);
		initTimekeeperPsudoSup();
		initADC7866Default();
		switch (code) {
			case 1:
//				univ_fbk_uart0_init(pLimit, baudRate, parity, parSense);
				univ_fbk_uart_sendTestBytes(15);
				sprintf(responseBuffer, "Sending 15 bytes over UART");
				break;
			case 2:
				sscanf(Argv[2].c_str(),"%d",&bytes);
				univ_fbk_uart_sendTestBytes(bytes);
				sprintf(responseBuffer, "Sending %d bytes over UART", bytes);
				break;
			case 3:
				for (i = 0; i<1000;i++){
					test = is_univ_fbk_uart_xmt_complete();
					if(test==0){
					 univ_fbk_uart_sendTestBytes(5);
					}
					else{
						for (timer = 0;timer<100000;timer++){
							int timer2 = 0;
							timer2 = timer2+1;
						}
					}
				}
				sprintf(responseBuffer, "Sending 500 bytes over UART");
				break;
			case 4:
				uint16 moduleid = adc7866_get_module_id();
				char *moduleidstat = new char [10];
				char *scratchStat = new char [10];

				if(moduleid==KNX_IP_ADC7866_MODID){
					std::strcpy(moduleidstat, "Succeeded");
				}
				else{
					std::strcpy(moduleidstat, "Failed");
				}

				int scratch_stat;
				scratch_stat = adc7866_test_scratch();
				sprintf(responseBuffer, "ADC Module ID is %d and has %s \n "
						"Scratch returned %d (1:Success, 0: Failure)", moduleid, moduleidstat, scratch_stat);
				break;
			case 5:
				adc7866_test_scratch_zero();
				break;
			case 6:
				SetADCCountsPerChannel(1);
				sprintf(responseBuffer, "Set PADCCNT to 1");
				break;
			case 7:
				sscanf(Argv[2].c_str(),"%d",&subArg);
				SetADCCountsPerChannel(subArg);
				sprintf(responseBuffer, "Set PADCCNT to %d",subArg);
				break;
			case 8:
				SetADCDelay(0);
				sprintf(responseBuffer, "Set DELPADC to 0");
				break;
			case 9:
				sscanf(Argv[2].c_str(),"%d",&subArg);
				SetADCDelay(subArg);
				sprintf(responseBuffer, "Set DELPADC to %d",subArg);
				break;
			case 10:
				sscanf(Argv[2].c_str(),"%d",&subArg);
				adcRingBuff(subArg);
				sprintf(responseBuffer, "\nCaptured %d samples to the Buffer",subArg);
				break;
			case 11:
				sscanf(Argv[2].c_str(),"%d",&subArg);
				verifyADCScaleRegisters();
				sprintf(responseBuffer, "\nCompleted ADC Scale Register Testr",subArg);
				break;
			default:
				sprintf(responseBuffer, "Nothing Done. No such Case. Running Case %d %d", code, subArg);
				break;
		}
		
		rResponseText = responseBuffer;
	}
	// too few or too many parameters
	else
	{
		rResponseText = "-03";
	}
	return;
}

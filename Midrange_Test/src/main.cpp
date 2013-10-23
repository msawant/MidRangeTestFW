#define HPI_TEST

#include "utils/Io_Stream.hpp"
#include "Datatypes.h"
#include "TestCases/MasterTestCase.hpp"  			//0
#include "TestCases/TimeKeeperTestCase.hpp"  		//1
#include "TestCases/DDRReadTestCase.hpp"
#include "TestCases/DDRWriteTestCase.hpp"
#include "TestCases/DDRWalkingOnesTestCase.hpp"
#include "TestCases/DDRGalpatTestCase.hpp"
#include "TestCases/DDRWriteZerosTestCase.hpp"
#include "TestCases/NANDReadTestCase.hpp"
#include "TestCases/NANDWriteCommandTestCase.hpp"
#include "TestCases/PHYTestCase.hpp"
#include "TestCases/GPIOTestCase.hpp"
#include "TestCases/Read16TestCase.hpp"
#include "TestCases/Write16TestCase.hpp"
#include "TestCases/EEPROMTestCase.hpp"
#include "TestCases/EMIFCSSpillTestCase.hpp"
#include "TestCases/LCDTestCase.hpp"
#include "Drivers/gpio.h"
#include "TestCases/UnivFbkTestCase.hpp"
#include "TestCases/DIGINTestCase.hpp"
// ****** INCLUDE NEW TEST CASE HEADERS HERE ****** //


#define MAX_ARGS		(16)
#define MAX_TEST_CASES	(32)
void configure_gpio();

int main(){

	std::string inputCommandString;
	std::string responseText;
	std::string argString[MAX_ARGS];

	int16 commandNumber = 0;
	int16 testCaseArrayIndex = 0;
	
	TestCase* pTestCaseArray[MAX_TEST_CASES];
	
	
	// create the test cases
	pTestCaseArray[testCaseArrayIndex++] = new MasterTestCase();				//00
	pTestCaseArray[testCaseArrayIndex++] = new DDRReadTestCase();				//10
	pTestCaseArray[testCaseArrayIndex++] = new DDRWriteTestCase();				//20
	pTestCaseArray[testCaseArrayIndex++] = new DDRWalkingOnesTestCase();		//21
	pTestCaseArray[testCaseArrayIndex++] = new DDRGalpatTestCase();				//100
	pTestCaseArray[testCaseArrayIndex++] = new DDRWriteZerosTestCase();			//22
	pTestCaseArray[testCaseArrayIndex++] = new NANDReadTestCase();				//11	
	pTestCaseArray[testCaseArrayIndex++] = new NANDWriteCommandTestCase();		//24
	pTestCaseArray[testCaseArrayIndex++] = new PHYTestCase();					//30
	pTestCaseArray[testCaseArrayIndex++] = new GPIOTestCase();					//40
	pTestCaseArray[testCaseArrayIndex++] = new Read16TestCase();				//16
	pTestCaseArray[testCaseArrayIndex++] = new Write16TestCase();				//17
	pTestCaseArray[testCaseArrayIndex++] = new EMIFCSSpillTestCase();			//31
    pTestCaseArray[testCaseArrayIndex++] = new LCDTestCase();                   //50
    pTestCaseArray[testCaseArrayIndex++] = new UnivFbkTestCase();               //60
	pTestCaseArray[testCaseArrayIndex++] = new DIGINTestCase();               	//70
	pTestCaseArray[testCaseArrayIndex++] = new TimeKeeperTestCase();			//01
	// Perform Autonomous Tests
	printf("\n \n Performing Autonomous MidRange Testing \n \n");
	
	// Run Test Cases Independently
	//responseText = "Autonomous Test";

	// Setup for NAND Test
	argString[1] = "24\r";
	pTestCaseArray[6]->Run(1, argString, responseText);

	// Setup for DDR Test
	//argString[1] = "21\r";
	//pTestCaseArray[2]->Run(1, argString, responseText);
    
        //LCD_RST
        argString[1] = "6\r";
        argString[2] = "12\r";
        argString[3] = "0\r";
        pTestCaseArray[8]->Run(4, argString, responseText);
        
        //LCD_BL
        argString[1] = "0\r";
        argString[2] = "7\r";
        argString[3] = "0\r";
        pTestCaseArray[8]->Run(4, argString, responseText);

        
        //LED1
        argString[1] = "0\r";
        argString[2] = "0\r";
        argString[3] = "1\r";
        pTestCaseArray[8]->Run(4, argString, responseText);
              
        //LED2        
        argString[1] = "0\r";
        argString[2] = "1\r";
        argString[3] = "1\r";
        pTestCaseArray[8]->Run(4, argString, responseText);
        
        //LED3
        argString[1] = "0\r";
        argString[2] = "2\r";
        argString[3] = "1\r";
        pTestCaseArray[8]->Run(4, argString, responseText);
        
        //LED4
        argString[1] = "0\r";
        argString[2] = "3\r";
        argString[3] = "1\r";
        pTestCaseArray[8]->Run(4, argString, responseText);    

        //LCD_A0
        argString[1] = "8\r";
        argString[2] = "8\r";
        argString[3] = "0\r";
        pTestCaseArray[8]->Run(4, argString, responseText);
        
        //LCD_CS0
        argString[1] = "6\r";
        argString[2] = "0\r";
        argString[3] = "0\r";
        pTestCaseArray[8]->Run(4, argString, responseText);
        
        //LCD_ERD
        argString[1] = "8\r";
        argString[2] = "11\r";
        argString[3] = "1\r";
        pTestCaseArray[8]->Run(4, argString, responseText);
        
        //LCD_RWR
        argString[1] = "8\r";
        argString[2] = "9\r";
        argString[3] = "0\r";
        pTestCaseArray[8]->Run(4, argString, responseText);

	// Setup for Power Supply PWM
	//uint16 dataWrite = 0x00000001;
    	
	// ****** ADD NEW TEST CASES HERE ****** //	

	
	Io_Stream* pIo_Stream = new Io_Stream();
	pIo_Stream->Io_StreamPutLine("Welcome to MrDrive Control Board Testing");
	
	while (1)
	{
		std::string::size_type pos=0, prev_pos=0;
		int16 totalArgs = 0;	
		bool foundTestCase = false;
		responseText.clear();
		
		// TODO: Take this line out for Mfg test code
		pIo_Stream->Io_StreamPutLine("Enter Test Command:");
		inputCommandString = pIo_Stream->Io_StreamGetLine();
		
		//echo input for debug
		// pIo_Stream->Io_StreamPutLine(inputCommandString);
		
		// parse the inputCommandString looking for a <space> and tokenize each word into an array of strings
		while( ((pos = inputCommandString.find(' ', pos)) != std::string::npos) && (totalArgs < MAX_ARGS-1) )
		{
			argString[totalArgs++] = inputCommandString.substr(prev_pos, pos-prev_pos);
			prev_pos = ++pos;
		}
		// get the last word
		argString[totalArgs++] = inputCommandString.substr(prev_pos, pos-prev_pos);
		
		// get the first argument and save the command number for deciding which test case to run
		if (totalArgs >= 1)
		{
			// get the command number from the first argument 
			commandNumber = atoi(argString[0].c_str());

			// find the test case to run based on the commandNumber
			for (int16 index=0 ; ((index < testCaseArrayIndex) && !foundTestCase) ; index++)
			{
				if (pTestCaseArray[index]->GetCommandNumber() == commandNumber)
				{
					foundTestCase = true;
					// run the test case
					pTestCaseArray[index]->Run(totalArgs, argString, responseText);
				}	
			}
		}
		// error response if there were no arguments or we did not find the test case
		if ((totalArgs == 0) || !foundTestCase)
		{
			pIo_Stream->Io_StreamPutLine("-01");
		}
		// otherwise, print the result of the test case
		else 
		{
			pIo_Stream->Io_StreamPutLine(responseText);		
		}
		
		for(int x=0; x < totalArgs; x++)
		{
			argString[x]="";
		}
	}
	return 0;
}

void configure_gpio(){
    GPIO_SetPinDirection(BANK4, PIN0, OUT);
    GPIO_SetPinDirection(BANK6, PIN8, IN);      //Key_0
    GPIO_SetPinDirection(BANK6, PIN9, IN);      //Key_2
    GPIO_SetPinDirection(BANK6, PIN10, IN);     //Key_3
    GPIO_SetPinDirection(BANK6, PIN11, IN);     //Key_1
}

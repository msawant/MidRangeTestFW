#include "DIGINTestCase.hpp"
#include "drivers/digin.h"

//Base Class Constructor
//Constructor
DIGINTestCase::DIGINTestCase()
:TestCase(TEST_CASE_ID_DIGIN_TEST){
 //do nothing	
}

DIGINTestCase::~DIGINTestCase(){
	//do nothing
}


void DIGINTestCase::Run(
int16 Argc,					// number of arguments
std::string* Argv,			// pointer to array variable argument
std::string &rResponseText	// reference string to place the response text
)
							
{
	// Check to make sure the correct number of arguments was passed in for
	// this test case.
	if (Argc == DIGIN_REQUIRED_ARGS)
	{	uint16 code = 0;
		char responseBuffer[32];
		sscanf(Argv[0].c_str(),"%X",&code);
		int status = digin_get_module_id();
		sprintf(responseBuffer, "%d", status);
		rResponseText = responseBuffer;
	}
	// too few or too many parameters
	else
	{
		rResponseText = "-03";
	}
	return;
}

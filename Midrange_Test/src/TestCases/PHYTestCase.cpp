#include "PHYTestCase.hpp"

#include <stdio.h>
#include <ti/pspiom/cslr/cslr.h>
#include <ti/pspiom/cslr/soc_OMAPL138.h>
#include <ti/pspiom/cslr/cslr_mdio.h>

CSL_MdioRegsOvly MDIO_REGS = (CSL_MdioRegsOvly)CSL_MDIO_0_REGS ;


// class constructor
PHYTestCase::PHYTestCase() 
: TestCase(TEST_CASE_ID_PHY)
{
	// do nothing
}

// class destructor
PHYTestCase::~PHYTestCase()
{
}

/////////////////////////////////////////////////////////////////////////////
// The DDR Write test case reads the memory data at the address passed in   //
// the second argument.  A successful read will return the test case       //
// number followed by the memory data in the rResponseText string.         //
/////////////////////////////////////////////////////////////////////////////
void PHYTestCase::Run
(
	int16 Argc, 				// number of arguments
	std::string* Argv,			// pointer to array variable argument 
	std::string &rResponseText	// reference string to place the response text 
)
{
	
	
	//CSL_FINST(MDIO_REGS->, PER_REG_FIELD, TOKEN)
//	// Check to make sure the correct number of arguments was passed in for
//	// this test case.
	if (Argc == PHY_REQUIRED_ARGS)
	{
		uint32 phyadr = 0;
		uint32 regadr = 0;
		uint32 data  = 0;
		
		
//		uint32 memWrittenData=0;
		char responseBuffer[32];
		
		//set up mdio in code

		sscanf(Argv[1].c_str(),"%X",phyadr);
		sscanf(Argv[2].c_str(),"%X",regadr);
		
//		CSL_FMK(MDIO_USERACCESS0_REGADR,0x00001234);
		PHYREG_wait();
		//PHYREG_read(regadr,phyadr);
		//PHYREG_waitResults(data);		
		

		sprintf(responseBuffer, "%d %X",TEST_CASE_ID_PHY,data);
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

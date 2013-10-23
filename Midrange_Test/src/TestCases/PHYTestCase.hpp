#ifndef PHYTESTCASE_HPP_
#define PHYTESTCASE_HPP_

#include "TestCase.hpp"
#include <stdio.h>
#include <ti/pspiom/cslr/cslr.h>
#include <ti/pspiom/cslr/soc_OMAPL138.h>
#include <ti/pspiom/cslr/cslr_mdio.h>

// define the test case ID number
#define TEST_CASE_ID_PHY	(30)


#define PHYREG_read(regadr, phyadr) {			\
	MDIO_REGS->USERACCESS0 = 					\
	CSL_FMK(MDIO_USERACCESS0_GO,1u) | 			\
	CSL_FMK(MDIO_USERACCESS0_REGADR,regadr) | 	\
	CSL_FMK(MDIO_USERACCESS0_PHYADR,phyadr);		\
}
#define PHYREG_write(regadr, phyadr, data){		\
	MDIO_REGS->USERACCESS0 = 					\
	CSL_FMK(MDIO_USERACCESS0_GO,1u) | 			\
	CSL_FMK(MDIO_USERACCESS0_WRITE,1) | 		\
	CSL_FMK(MDIO_USERACCESS0_REGADR,regadr) | 	\
	CSL_FMK(MDIO_USERACCESS0_PHYADR,phyadr) | 	\
	CSL_FMK(MDIO_USERACCESS0_DATA, data);		\
}

#define PHYREG_wait(){												\
	while( CSL_FEXT(MDIO_REGS->USERACCESS0,MDIO_USERACCESS0_GO) );	\
}

#define PHYREG_waitResults( results ){\
	while( CSL_FEXT(MDIO_REGS->USERACCESS0,MDIO_USERACCESS0_GO) );\
results = CSL_FEXT(MDIO_REGS->USERACCESS0, MDIO_USERACCESS0_DATA);\
}



class PHYTestCase : public TestCase
{
public:
	// Public constructor
	PHYTestCase();
	
	// destructor
	virtual ~PHYTestCase();
	
	// run method for the test case
	virtual void Run
	(
		int16 Argc, 
		std::string* Argv,
		std::string &rResponseText
	);
	
	
private:
	enum PHY_Arguments
	{
		PHY_ARG_COMMAND_NUM	= 0,
		PHY_ARG_PHY_ADDRESS	= 1,
		PHY_ARG_REG_ADDRESS	= 2,
		PHY_REQUIRED_ARGS	= 3
	};
};

#endif /*PHYTESTCASE_HPP_*/

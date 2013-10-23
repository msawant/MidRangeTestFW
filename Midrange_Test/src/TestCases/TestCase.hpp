#ifndef TESTCASE_HPP_
#define TESTCASE_HPP_

#define DDR_START_ADDR 			(0xC0000000)
#define DDR_END_ADDR			(0xC3FFFFFF)
#define KMCL_START_ADDR			(0x60000000)
#define KMCL_END_ADDR			(0X6000FFFE)
#define EMIF_NAND_START_ADDR	(0x62000000)
#define EMIF_NAND_END_ADDR		(0x63FFFFFF)

#define READMEM32(pMem) 		(*(volatile uint32*)(pMem))
#define WRITEMEM32(pMem, data) 	((*(volatile uint32*)(pMem)) = data)

#include "../Datatypes.h"

#include <string>

using namespace std;

class TestCase
{
public:
	// Public constructor
	TestCase(const int16 CommandNumber);
	
	// Member Function Declaration
	void EraseDDR(uint32 memStartEraseAddress, uint32 memEndEraseAddress);
	void WriteAllDDRZero(void);
	void WriteAllDDROne(void);
	
	// pure virtual method for running the test case
	virtual void Run
	(
		int16 Argc, 
		std::string* Argv,
		std::string &rResponseText
	) = 0;
	
	void Help(void);
	
	// destructor	 
	virtual ~TestCase();

	// inline method for returning the command number of the test case
	int16 GetCommandNumber() {return m_CommandNumber;}
	
protected:
	// storage for the command number of the test case
	int16 m_CommandNumber;
	

	enum CommandReturnErrorStatus
	{
		ERROR_STATUS_UNRECOGNIZED_CMD	= -1,
		ERROR_STATUS_PARITY_ERROR		= -2,
		ERROR_STATUS_NUM_OF_PARAMETERS	= -3,
		ERROR_STATUS_INVALID_PARAMETERS	= -4,
		ERROR_STATUS_TERMINATOR_MISSING	= -5,
		ERROR_STATUS_CHARACTER_ERROR	= -6,
		ERROR_STATUS_TEST_COMMAND_FAIL	= -7
	};

	enum ModuleIds
	{
		KNX_IP_ADC7866_MODID 			= 0x090
	};

};

#endif /*TESTCASE_HPP_*/

#ifndef DIGINTESTCASE_HPP_
#define DIGINTESTCASE_HPP_

#include "TestCase.hpp"
#include "drivers/digin.h"

#define TEST_CASE_ID_DIGIN_TEST	(70)
// some handy macros for reading/writing to memory

class DIGINTestCase : public TestCase
{
public:
	// Public constructor
	DIGINTestCase();
	
	// destructor
	~DIGINTestCase();
	
	void Run
	(
		int16 Argc, 
		std::string* Argv,
		std::string &rResponseText
	);
	
	
private:
	enum DIGIN_Arguments
	{
		DIGIN_ARG_COMMAND_NUM	= 0,
		DIGIN_REQUIRED_ARGS		= 2
	};
};

#endif /*DIGINTESTCASE_HPP_*/

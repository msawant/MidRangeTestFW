#ifndef UNIVFBKTESTCASE_HPP_
#define UNIVFBKTESTCASE_HPP_
#include "TestCase.hpp"


		
// some handy macros for reading/writing to memory

#define TEST_CASE_ID_UNIV_FBK_TEST	(60)
#define WRITEMEM16(pMem, data) 	((*(volatile uint16*)(pMem)) = data)


class UnivFbkTestCase : public TestCase
{
public:
	// Public constructor
	UnivFbkTestCase();
	
	// destructor
	~UnivFbkTestCase();
	
	void Run
	(
		int16 Argc, 
		std::string* Argv,
		std::string &rResponseText
	);
	
private:
	enum Univ_Fbk_Arguments
	{
		UNIV_FBK_ARG_COMMAND_NUM		= 0,
		UNIV_FBK_ARG_SUB_COMMAND_NUM	= 1,
		UNIV_FBK_REQUIRED_ARGS			= 2,
		UNIV_FBK_MAX_ARGS				= 4,
	};
};
#endif /*UNIVFBKTESTCASE_HPP_*/

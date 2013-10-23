/*
 * MasterTestCase.hpp
 *
 *  Created on: Oct 11, 2013
 *      Author: msawant
 */

#ifndef MASTERTESTCASE_HPP_
#define MASTERTESTCASE_HPP_
#include "TestCase.hpp"



// some handy macros for reading/writing to memory

#define TEST_CASE_ID_MASTER_TEST	(0)


class MasterTestCase : public TestCase
{
public:
	// Public constructor
	MasterTestCase();

	// destructor
	~MasterTestCase();

	void Run
	(
		int16 Argc,
		std::string* Argv,
		std::string &rResponseText
	);

private:
	enum Master_Test_Arguments
	{
		MASTER_TEST_ARG_COMMAND_NUM		= 0,
		MASTER_TEST_SUB_COMMAND_NUM		= 1,
		MASTER_TEST_REQUIRED_ARGS		= 2
	};
};

#endif /* MASTERTESTCASE_HPP_ */

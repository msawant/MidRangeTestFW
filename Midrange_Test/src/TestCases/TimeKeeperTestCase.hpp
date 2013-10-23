/*
 * TimeKeeperTestCase.hpp
 *
 *  Created on: Oct 15, 2013
 *      Author: miglab
 */

#ifndef TIMEKEEPERTESTCASE_HPP_
#define TIMEKEEPERTESTCASE_HPP_

#include "TestCase.hpp"


#define TEST_CASE_ID_TIMEKEEPER_TEST	(1)


class TimeKeeperTestCase : public TestCase
{
public:
	// Public constructor
	TimeKeeperTestCase();

	// destructor
	~TimeKeeperTestCase();

	void Run
	(
		int16 Argc,
		std::string* Argv,
		std::string &rResponseText
	);

private:
	enum TimeKeeper_Test_Arguments
	{
		TIMEKEEPER_TEST_ARG_COMMAND_NUM		= 0,
		TIMEKEEPER_TEST_SUB_COMMAND_NUM		= 1,
		TIMEKEEPER_TEST_REQUIRED_ARGS		= 2
	};
};


#endif /* TIMEKEEPERTESTCASE_HPP_ */

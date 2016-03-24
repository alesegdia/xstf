#pragma once

#include <string>
#include <vector>
#include <iostream>

#define TEST_CHECK(bench, cond, msg) bench.check(cond, msg, __LINE__)

class TestBench {
private:
	class TestCheck {
	public:
		TestCheck( int line, bool success, const char* msg )
			: m_line(line), m_success(success), m_msg(msg)
		{

		}

		int line()
		{
			return m_line;
		}

		bool success()
		{
			return m_success;
		}

	private:
		int m_line = -1;
		bool m_success = false;
		std::string m_msg = "";

	};

public:

	TestBench( const char* name )
		: m_testName(name)
	{

	}

	void check( bool condition, const char* msg, int line )
	{
		TestCheck tc(line, condition, msg);
		m_successAll = m_successAll && condition;

		if( !condition )
		{
			printf("FAILED (%d): %s\n", line, msg);
		}
	}

	bool successAll()
	{
		return !m_successAll;
	}

private:
	std::string m_testName;
	bool m_successAll = true;
	std::vector<TestCheck> m_checks;

};

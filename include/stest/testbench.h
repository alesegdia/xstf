#pragma once

#include <string>
#include <vector>
#include <iostream>

#define TEST_CHECK(bench, cond, msg) bench.check(cond, msg, __LINE__)

namespace stest {

class TestBench {
private:
	class TestCheck {
	public:
		TestCheck( int line, bool success, const char* msg );

		int line();
		bool success();

	private:
		int m_line = -1;
		bool m_success = false;
		std::string m_msg = "";

	};

public:

	TestBench( const char* name );

	void check( bool condition, const char* msg, int line );
	bool successAll();

private:
	std::string m_testName;
	bool m_successAll = true;
	std::vector<TestCheck> m_checks;

};

}

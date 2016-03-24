
#include "xstf/testbench.h"

namespace xstf
{


TestBench::TestCheck::TestCheck(int line, bool success, const char *msg)
	: m_line(line), m_success(success), m_msg(msg)
{

}

int TestBench::TestCheck::line()
{
	return m_line;
}

bool TestBench::TestCheck::success()
{
	return m_success;
}

TestBench::TestBench(const char *name)
	: m_testName(name)
{

}

void TestBench::check(bool condition, const char *msg, int line)
{
	TestCheck tc(line, condition, msg);
	m_successAll = m_successAll && condition;

	if( !condition )
	{
		printf("FAILED (%d): %s\n", line, msg);
	}
}

bool TestBench::successAll()
{
	return !m_successAll;
}


}

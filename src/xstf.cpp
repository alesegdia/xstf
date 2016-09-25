
#include "xstf.h"

namespace xstf
{

TestBench::TestBench(const char *name)
	: m_testName(name)
{
	printf("STARTING TESTBENCH [%s]\n", name);
}

TestBench::~TestBench()
{
	printf("\nFINISHED TESTBENCH [%s]\n\n", m_testName);
}

void TestBench::check(TestBenchScopeHelper &tbsh, bool condition, const char *msg, int line)
{
	m_successAll = m_successAll && condition;

	if( false == condition )
	{
		tbsh.m_success = false;
		m_successAll = false;
		printf("FAILED  (%d): %s\n", line, msg);
	}
	else if( m_enableVerboseSuccess )
	{
		printf("SUCCESS (%d): %s\n", line, msg);
	}
}

bool TestBench::successAll()
{
	return false == m_successAll;
}

void TestBench::enableVerboseSuccess(bool value)
{
	m_enableVerboseSuccess = value;
}

TestBench::TestBenchScopeHelper::TestBenchScopeHelper(TestBench& tb, const char *name )
	: m_testbench(tb),
	  m_name(name)
{
	printf("\n>> STARTING TEST [%s]\n", name);
}

TestBench::TestBenchScopeHelper::~TestBenchScopeHelper()
{
	if( m_success )
	{
		printf("<< [SUCCESS]");
	}
	else
	{
		printf("<< [FAIL]");
	}
	printf(" [%s] FINISHED\n", m_name);
	m_success = true;
}

}

#pragma once

#include <cstdio>

// general checks
#define XSTF_ASSERT(cond, msg)	xstf__testbench.check(cond, msg, __LINE__)
#define XSTF_EQUALS(a, b, msg) XSTF_ASSERT(a == b, msg)
#define XSTF_GT(a, b, msg) XSTF_ASSERT(a >  b, msg)
#define XSTF_GTE(a, b, msg) XSTF_ASSERT(a >= b, msg)
#define XSTF_LT(a, b, msg) XSTF_ASSERT(a <  b, msg)
#define XSTF_LTE(a, b, msg) XSTF_ASSERT(a <= b, msg)

// create test unit
#define XSTF_TESTBENCH(name) xstf::TestBench xstf__testbench(name)
#define XSTF_TEST_SUCCESS xstf__testbench.successAll()
#define XSTF_ALL_SUCCESS xstf__successAll
#define XSTF_SET_VERBOSITY_LEVEL(lvl) xstf__testbench.setVerbosityLevel(lvl)

#define XSTF_INIT bool xstf__successAll = false;
#define XSTF_RUN(test) xstf__successAll = xstf__successAll && test();
#define XSTF_TESTCASE(fn_name) bool fn_name()
#define XSTF_END_TESTCASE return xstf__successAll;

// verbosity levels
#define XSTF_VL_FULL 9
#define XSTF_VL_NULL 0

namespace xstf {

typedef bool (*TestCallback)();

class TestBench {
public:

    TestBench( const char* name )
        : m_testName(name)
    {
        printf("STARTING TESTBENCH [%s]\n", m_testName);
    }

    ~TestBench()
    {
        printf("\nFINISHED TESTBENCH [%s]\n\n", m_testName);
    }

    void check( bool condition, const char* msg, int line )
    {
        m_successAll = m_successAll && condition;

        if( false == condition )
        {
            printf("FAILED  (%d): %s\n", line, msg);
        }
        else if( shouldReportSuccess() )
        {
            printf("SUCCESS (%d): %s\n", line, msg);
        }
    }
	
	bool shouldReportSuccess()
	{
		return m_verbosityLevel >= XSTF_VL_FULL;
	}
	
    bool successAll()
    {
        return false == m_successAll;
    }

    void setVerbosityLevel( int level )
    {
        m_verbosityLevel = level;
    }

private:

	int m_verbosityLevel = XSTF_VL_FULL;
	const char* m_testName;
	bool m_successAll = true;

};

}

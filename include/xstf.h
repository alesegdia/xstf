#pragma once

#include <cstdio>

// general checks
#define XSTF_ASSERT(cond, msg)	xstf__testbench.check(xstf_testbench_scopehelper, cond, msg, __LINE__)
#define XSTF_EQUALS(a, b, msg) XSTF_ASSERT(a == b, msg)
#define XSTF_GT(a, b, msg) XSTF_ASSERT(a >  b, msg)
#define XSTF_GTE(a, b, msg) XSTF_ASSERT(a >= b, msg)
#define XSTF_LT(a, b, msg) XSTF_ASSERT(a <  b, msg)
#define XSTF_LTE(a, b, msg) XSTF_ASSERT(a <= b, msg)

// create test unit
#define XSTF_TEST(name) xstf::TestBench::TestBenchScopeHelper xstf_testbench_scopehelper(xstf__testbench, name);
#define XSTF_TESTING(name) xstf::TestBench xstf__testbench(name)
#define XSTF_TESTING_RESULT xstf__testbench.successAll()
#define XSTF_SET_VERBOSITY_LEVEL(lvl) xstf__testbench.setVerbosityLevel(lvl)

// verbosity levels
#define XSTF_VL_FULL 9
#define XSTF_VL_NULL 0

namespace xstf {

class TestBench {
public:

	class TestBenchScopeHelper
	{
	public:
		friend class TestBench;
        TestBenchScopeHelper(TestBench& tb, const char* name)
            : m_testbench(tb),
              m_name(name)
        {
            printf("\n>> STARTING TEST [%s]\n", name);
        }
        ~TestBenchScopeHelper()
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
	private:
		TestBench& m_testbench;
		const char* m_name;
		bool m_success = true;
	};

	friend class TestBenchScopeHelper;

    TestBench( const char* name )
        : m_testName(name)
    {
        printf("STARTING TESTBENCH [%s]\n", name);
    }
    ~TestBench()
    {
        printf("\nFINISHED TESTBENCH [%s]\n\n", m_testName);
    }

    void check( TestBenchScopeHelper& tbsh, bool condition, const char* msg, int line )
    {
        m_successAll = m_successAll && condition;

        if( false == condition )
        {
            tbsh.m_success = false;
            m_successAll = false;
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

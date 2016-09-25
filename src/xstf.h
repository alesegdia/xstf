#pragma once

#include <cstdio>

#define XSTF_ASSERT(cond, msg) xstf__testbench.check(xstf_testbench_scopehelper, cond, msg, __LINE__)
#define XSTF_TEST(name) xstf::TestBench::TestBenchScopeHelper xstf_testbench_scopehelper(xstf__testbench, name);
#define XSTF_TESTING(name) xstf::TestBench xstf__testbench(name)
#define XSTF_TESTING_RESULT xstf__testbench.successAll()
#define XSTF_ENABLE_VERBOSE_CHECKS xstf__testbench.enableVerboseSuccess(true)

namespace xstf {

class TestBench {
public:

	class TestBenchScopeHelper
	{
	public:
		friend class TestBench;
		TestBenchScopeHelper(TestBench& tb, const char* name);
		~TestBenchScopeHelper();
	private:
		TestBench& m_testbench;
		const char* m_name;
		bool m_success = true;
	};

	friend class TestBenchScopeHelper;

	TestBench( const char* name );
	~TestBench();

	void check( TestBenchScopeHelper& tbsh, bool condition, const char* msg, int line );
	bool successAll();

	void enableVerboseSuccess( bool value );

private:

	bool m_enableVerboseSuccess = false;
	const char* m_testName;
	bool m_successAll = true;

};

}

# XSTF

XSTF is an eXtremely Simple Test Framework.

## Why?

After checking a few available test frameworks, I feel they are a bloated. Maybe the reason of my thoughts is that I'm really noob at TDD, but I just couldn't find
a reason about why they were so big. Then, the goal of XSTF is to provide myself with a lightweight testing framework, and probably learning about TDD in the way.

## How?

```
#include <xstf/testbench.h>

int main( int argc, char** argv )
{
	xstf::Testbench tb("Sample");
	TEST_CHECK(tb, 2 == 3, "you are definitely dumb");
	return tb.successAll();
}
```

#include "../include/xstf.h"

int main(int argc, char** argv)
{
	XSTF_TESTING("Complex Maths Testing");
	XSTF_SET_VERBOSITY_LEVEL(XSTF_VL_FULL);
	
	{
		XSTF_TEST("Simple arithmetic");
		XSTF_EQUALS(1+1, 2, "Sum of two positive integers");
		XSTF_ASSERT(1+1 > 3, "Sum of two positive integers");
		XSTF_ASSERT(1+(-1)==0, "Sum of one positive integer with a negative integer");
	}
	
	{
		XSTF_TEST("Complex calculus");
		XSTF_ASSERT(1*1==1, "Multiplication of integers");
		XSTF_ASSERT(4/2==2, "Division of integers");
	}
	
	return 0;
}

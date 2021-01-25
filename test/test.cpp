#include "gtest/gtest.h"
#include "bi_tests.h"
#include "rn_tests.h"


int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
#include "gtest/gtest.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

int main(int argc, const char** argv) {
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
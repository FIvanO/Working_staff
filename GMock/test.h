#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "drawer.h"
#include "mockcalculatedirection.h"

using namespace testing;

TEST(Test1, Test1) {
	MockCalculateDirection m;
	int var = 4;
	EXPECT_CALL(m, calculate(var)).WillOnce(Return(0));
	Drawer drawer;
	ASSERT_TRUE(drawer.draw(m, var));
}

TEST(Test2, Test2) {
	MockCalculateDirection m;
	int var = 5;
	Drawer drawer;
	EXPECT_CALL(m, calculate(var)).WillOnce(Return(5));
	ASSERT_TRUE(drawer.draw(m, var));
}

TEST(Test3, Test3) {
	MockCalculateDirection m;
	int var = 6;
	Drawer drawer;
	EXPECT_CALL(m, calculate(var)).WillOnce(Return(2));
	ASSERT_TRUE(drawer.draw(m, var));
}

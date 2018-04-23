#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "drawer.h"
#include "mockcalculatedirection.h"

using namespace testing;

TEST(Test, Test) {
	MockCalculateDirection m;
	EXPECT_CALL(m, calculate(4)).WillOnce(Return(0));
	EXPECT_CALL(m, calculate(5)).WillOnce(Return(1));
	EXPECT_CALL(m, calculate(6)).WillOnce(Return(2));
	EXPECT_CALL(m, calculate(7)).WillOnce(Return(3));
}

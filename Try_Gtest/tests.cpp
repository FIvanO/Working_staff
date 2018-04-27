//#include <QCoreApplication>
#include <vector>
#include <gtest/gtest.h>
#include "somemathfunc.h"

std::vector < std::pair <int, int> > vi = {
{ 1, 1 }, { 6, 3}, { 3628800, 10 }, { 1, 0 }
};

INSTANTIATE_TEST_CASE_P(ParametrTest1, SomeMathFuncForParametr, ::testing::ValuesIn(vi));

TEST_P(SomeMathFuncForParametr, ParametrTestFactCorrect) {
	std::pair <int, int> test_case = GetParam();
	EXPECT_EQ(test_case.first, fact(test_case.second));
}

TEST_F(SomeMathFunc, fewPositiveCorrect) {
	EXPECT_EQ(1, fact(1));
	EXPECT_EQ(6, fact(3));
	EXPECT_EQ(3628800, fact(10));
}

TEST_F(SomeMathFunc, fewPositiveWrong) {
	EXPECT_EQ(0, fact(1));
	EXPECT_EQ(6, fact(3));
	EXPECT_EQ(3628800, fact(10));
}

TEST_F(SomeMathFunc, NullTestCorrect) {
	EXPECT_EQ(1, SomeMathFunc::fact(0));
}

TEST_F(SomeMathFunc, NullTestWrong) {
	EXPECT_EQ(0, SomeMathFunc::fact(0));
}

TEST_F(SomeMathFunc, fewTests) {
	EXPECT_EQ(1, gcd(2, 5));
	EXPECT_EQ(2, gcd(2, 4));
	EXPECT_EQ(4, gcd(4, 16));
	EXPECT_EQ(144, gcd(144, 288));
	EXPECT_EQ(1, gcd(123123, 123124));
}

TEST_F(SomeMathFunc, fewTestsWrong) {
	EXPECT_EQ(5, gcd(2, 5));
	EXPECT_EQ(2, gcd(2, 4));
	EXPECT_EQ(4, gcd(4, 16));
	EXPECT_EQ(144, gcd(144, 288));
	EXPECT_EQ(1, gcd(123123, 123124));
}

//std::vector < std::pair <int, int> > vi1 = {
//{ 1, 0 }, { 6, 3}, { 3628800, 10 }, { 1, 0 }
//};

//TEST_P(SomeMathFuncForParametr, ParametrTestFactWrong) {
//	std::pair <int, int> test_case = GetParam();
//	EXPECT_EQ(test_case.first, fact(test_case.second));
//}

//INSTANTIATE_TEST_CASE_P(ParametrTestFactWrong, SomeMathFuncForParametr, ::testing::ValuesIn(vi1));

/*TEST(SomeMathFunc1, fewPos) {
	EXPECT_EQ(1, fact(1));
	EXPECT_EQ(6, fact(3));
	EXPECT_EQ(3628800, fact(10));
}

TEST(SomeMathFunc3, NullTest) {
	EXPECT_EQ(1, fact(0));
}

TEST(SomeMathFunc4, fewT) {
	EXPECT_EQ(1, gcd(2, 5));
	EXPECT_EQ(2, gcd(2, 4));
	EXPECT_EQ(4, gcd(4, 16));
	EXPECT_EQ(144, gcd(144, 288));
	EXPECT_EQ(1, gcd(123123, 123124));
}

TEST(SomeMathFunc5, fewT1) {
	EXPECT_EQ(1, gcd(2, 5));
	EXPECT_EQ(2, gcd(2, 4));
	EXPECT_EQ(4, gcd(4, 16));
	EXPECT_EQ(144, gcd(144, 288));
	EXPECT_EQ(1, gcd(123123, 123124));
}*/



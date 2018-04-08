//#include <QCoreApplication>
#include "main.cpp"
#include <gtest/gtest.h>

/*
TEST_F(SomeMathFunc, fewPos) {
    EXPECT_EQ(1, fact(1));
    EXPECT_EQ(6, fact(3));
    EXPECT_EQ(3628800, fact(10));
}

TEST_F(SomeMathFunc, fewPos1) {
    EXPECT_EQ(1, fact(1));
    EXPECT_EQ(6, fact(3));
    EXPECT_EQ(3628800, fact(10));
}

TEST_F(SomeMathFunc, NullTest) {
    EXPECT_EQ(1, SomeMathFunc::fact(0));
}

TEST_F(SomeMathFunc, fewT) {
    EXPECT_EQ(1, gcd(2, 5));
    EXPECT_EQ(2, gcd(2, 4));
    EXPECT_EQ(4, gcd(4, 16));
    EXPECT_EQ(144, gcd(144, 288));
    EXPECT_EQ(1, gcd(123123, 123124));
}

TEST_F(SomeMathFunc, fewT1) {
    EXPECT_EQ(1, gcd(2, 5));
    EXPECT_EQ(2, gcd(2, 4));
    EXPECT_EQ(5, gcd(4, 16));
    EXPECT_EQ(144, gcd(144, 288));
    EXPECT_EQ(1, gcd(123123, 123124));
}
*/

TEST(SomeMathFunc1, fewPos) {
    EXPECT_EQ(1, fact(1));
    EXPECT_EQ(6, fact(3));
    EXPECT_EQ(3628800, fact(10));
}

TEST(SomeMathFunc2, fewPos1) {
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
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
}


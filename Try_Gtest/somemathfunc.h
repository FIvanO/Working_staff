#ifndef SOMEMATHFUNC_H
#define SOMEMATHFUNC_H
#include <gtest/gtest.h>

class SomeMathFunc : public ::testing::Test  {
public:
	int fact(int n);
	int gcd(int a, int b);
};

class SomeMathFuncForParametr : public SomeMathFunc, public ::testing::WithParamInterface<std::pair <int, int> > {

};

#endif // SOMEMATHFUNC_H

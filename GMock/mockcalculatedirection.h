#ifndef MOCKCALCULATEDIRECTION_H
#define MOCKCALCULATEDIRECTION_H
#include "calculatedirection.h"
#include <gmock/gmock.h>

class MockCalculateDirection : public CalculateDirection
{
public:
	~MockCalculateDirection() {}
	MOCK_CONST_METHOD1(calculate, int(int x));
};

#endif // MOCKCALCULATEDIRECTION_H

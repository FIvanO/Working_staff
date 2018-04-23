#ifndef CALCULATEDIRECTION_H
#define CALCULATEDIRECTION_H


class CalculateDirection
{
public:
	CalculateDirection() {}
	virtual ~CalculateDirection() {}
	virtual int calculate(int inputData) const = 0;
};

#endif // CALCULATEDIRECTION_H

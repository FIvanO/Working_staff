#include "somemathfunc.h"

int SomeMathFunc::fact(int n) {
	return n == 0 ? 1 : (n * fact(n - 1));
}

int SomeMathFunc::gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

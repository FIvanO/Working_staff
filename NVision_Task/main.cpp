#include <iostream>
#include <numeric>
#include <iomanip>
#include <chrono>

using std::cin;
using std::cout;
using std::endl;
using std::setw;

namespace matrix {

	size_t  fromTwoToOne(size_t  i, size_t  j, size_t  m) { // return index in one-dimansional array (from two-dimensional)
		return m * i + j;
	}

	void foo(int a[], size_t  m, size_t  indI, size_t  indJ, size_t  height, size_t  width) {
		std::chrono::time_point<std::chrono::system_clock> start, end;
		start = std::chrono::system_clock::now();
		// array, width of matrix, change matrix from index (indI, indJ), height and width of changeable part of matrix
		size_t  maxI = indI + (height / 2); // we're moving from indI to maxI (lines)
		size_t  lastString = indI + height - 1; // number of last line of changeable part of matrix
		size_t  maxJ = indJ + width; // max column's index of changeable part of matrix
		for (size_t  i = indI; i < maxI; ++i) {
//			if (height % 2 == 1 && i = maxI - 1) {
//				maxJ = indJ + width / 2;
//			}
			for (size_t  j = indJ; j < maxJ; ++j) {
				std::swap(a[fromTwoToOne(i, j, m)], a[fromTwoToOne(lastString - i + indI, maxJ - j + indJ - 1, m)]);
			}
		}
		if (height % 2 == 1) {
			// we have to change half of line, which is in the middle of changeable matrix
			indI += height / 2;
			size_t  halfMaxJ = indJ + width / 2; // middle index of this line
			for (size_t  j = indJ; j < halfMaxJ; ++j) {
				std::swap(a[fromTwoToOne(indI, j, m)], a[fromTwoToOne(indI, maxJ - j + indJ - 1, m)]);
			}
		}
		end = std::chrono::system_clock::now();
		size_t  elapsed_seconds = std::chrono::duration_cast<std::chrono::nanoseconds>
									(end-start).count();
		cout << elapsed_seconds << endl;
	}

}

void out(size_t  a[], size_t  n, size_t  m) { // out array, with n lines and m columns
	for (size_t  i = 0; i < n; ++i) {
		for (size_t  j = 0; j < m; ++j) {
			cout << setw(5) << a[matrix::fromTwoToOne(i, j, m)] << " ";
		}
		cout << endl;
	}
}

void getData(size_t  &n, size_t  &m, size_t  &indI, size_t  &indJ, size_t  &height, size_t  &width) {
	cout << "lines count: "; // width
	cin >> n;
	cout << "columns count: "; // height
	cin >> m;
	cout << "change matrix from index (matrix start in (0, 0) )" << endl;
	cout << "i: ";
	cin >> indI;
	cout << "j: ";
	cin >> indJ;
	cout << "height: ";
	cin >> height; // heigth of changeable matrix
	cout << "width: ";
	cin >> width; // width of changeable matrix
	cout << endl;
}

int main()
{
	size_t  n, m, indI, indJ, height, width;
	getData(n, m, indI, indJ, height, width);

	const size_t N = n * m;
	int  *arr = new int[N];
	std::iota(arr, arr + N, 1);

//	cout << "matrix before changing: " << endl;
//	out(arr, n, m);

	matrix::foo(arr, m, indI, indJ, height, width);

	cout << endl;
	cout << endl;

//	cout << "matrix after changing:" << endl;
//	out(arr, n, m);

	return 0;
}

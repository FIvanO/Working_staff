#include <iostream>
#include <numeric>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::setw;

namespace matrix {

	int fromTwoToOne(int i, int j, int m) { // return index in one-dimansional array (from two-dimensional)
		return m * i + j;
	}

	void foo(int a[], int m, int indI, int indJ, int height, int width) {
		// array, width of matrix, change matrix from index (indI, indJ), height and width of changeable part of matrix
		int maxI = indI + (height / 2); // we're moving from indI to maxI (lines)
		int lastString = indI + height - 1; // number of last line of changeable part of matrix
		int maxJ = indJ + width; // max column's index of changeable part of matrix
		for (int i = indI; i < maxI; ++i) {
			for (int j = indJ; j < maxJ; ++j) {
				std::swap(a[fromTwoToOne(i, j, m)], a[fromTwoToOne(lastString - i + indI, maxJ - j + indJ - 1, m)]);
			}
		}
		if (height % 2 == 1) {
			// we have to change half of line, which in the middle of changeable matrix
			indI += height / 2;
			int halfMaxJ = indJ + width / 2; // middle index of this line
			for (int j = indJ; j < halfMaxJ; ++j) {
				std::swap(a[fromTwoToOne(indI, j, m)], a[fromTwoToOne(indI, maxJ - j + indJ - 1, m)]);
			}
		}
	}

}

void out(int a[], int n, int m) { // out array, with n lines and m columns
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << setw(5) << a[matrix::fromTwoToOne(i, j, m)] << " ";
		}
		cout << endl;
	}
}

void getData(int &n, int &m, int &indI, int &indJ, int &height, int &width) {
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
	int n, m, indI, indJ, height, width;
	getData(n, m, indI, indJ, height, width);

	const int N = n * m;
	int arr[N];
	std::iota(arr, arr + N, 1);

	cout << "matrix before changing: " << endl;
	out(arr, n, m);

	matrix::foo(arr, m, indI, indJ, height, width);

	cout << endl;
	cout << endl;

	cout << "matrix after changing:" << endl;
	out(arr, n, m);

	return 0;
}

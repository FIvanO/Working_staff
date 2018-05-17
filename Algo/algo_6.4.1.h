#ifndef ALGO_6_4_1_H
#define ALGO_6_4_1_H

#include <iostream>

using namespace std;

int algo641() {
	int n;
	cin >> n;
	int a[n + 5];

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (a[i] > a[j]) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}


#endif // ALGO_6_4_1_H

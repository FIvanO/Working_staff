#ifndef ALGO_4_3_1_H
#define ALGO_4_3_1_H

#include <iostream>
#include <string>
#include <set>

using namespace std;

int algo431() {
	int n;
	string in;

	cin >> n;
	multiset <int> s;
	for (int i = 0; i < n; ++i) {
		cin >> in;
		if (in == "ExtractMax") {
			int ans = *(s.begin());
			s.erase(s.begin());
			cout << -ans << endl;
		}
		else {
			int k;
			cin >> k;
			s.insert(-k);
		}
	}

	return 0;
}


#endif // ALGO_4_3_1_H

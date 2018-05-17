#ifndef ALGO_4_1_2_H
#define ALGO_4_1_2_H

#include <cassert>
#include <cstdint>
#include <iostream>
#include <algorithm>
#define mp(x, y) std::make_pair(x, y)

using std::cin;
using std::cout;
using std::endl;

int algo_412() {
	int n, w;
	double res = 0;
	cin >> n >> w;
	std::pair<double, std::pair<int, int>> p[n + 5];
	for (int i = 0; i < n; ++i) {
		int a, b;
		double c;
		cin >> a >> b;
		c = double(a) / double(b);
		p[i] = mp(c, mp(a, b));
	}
	sort(p, p + n);
	reverse(p, p + n);

//    for (int i = 0; i < n; ++i) {
//        cout << "i: " << i << "; pr1: " << p[i].first << "; prAll: " << p[i].second.first << "; wAll: " << p[i].second.second << endl;
//    }
	for (int i = 0; i < n; ++i) {
		//cout << "w: " << w << endl;
		if (w == 0) {
			break;
		}
		if (w - p[i].second.second >= 0) {
			res += p[i].second.first;
			//cout << "res: " << res << endl;
			w -= p[i].second.second;
		} else
		{
			res += p[i].first * w;
			w = 0;
			break;
		}
	}

	cout.precision(3);
	cout << res << endl;
	return 0;
}


#endif // ALGO_4_1_2_H

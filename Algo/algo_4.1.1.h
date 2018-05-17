#ifndef ALGO_4_1_1_H
#define ALGO_4_1_1_H

#include <iostream>
#include <utility>
#include <map>

int algo_411(void) {
  int n;
  std::cin >> n;
  std::map <int, int> a;
  std::map <int, int> b;

  for (int i = 0; i < n; ++i)
	{
		int k;
		int val;
		std::cin >> k >> val;
		if (b[k] == 0) {
			b[k] = val;
		}
		else {
			b[k] = std::min(b[k], val);
		}
		//std::cout << k << " " << b[k] << std::endl;
	}

//    std::cout << "---------------" << std::endl;

//    for (auto m_b : b) {
//        std::cout << m_b.first << " " << m_b.second << std::endl;
//    }

//    std::cout << "---------------" << std::endl;

	for (auto m_b : b) {
		int l, r;
		bool flag = false;
		int c, d;
		l = m_b.first;
		r = m_b.second;
		for (auto k = a.begin(); k != a.end(); ++k) {
			//std::cout << "l: " << l << "; r: " << r << std::endl;
			//std::cout << "k->fir: " << k -> first << "; k->sec: " << k -> second << std::endl;
			if (k -> first <= l && l <= k -> second) {
				//k -> first = l;
				c = k -> first;
				d = std::min(k -> second, r);
				//std::cout << "k->sec: " << k -> second << "; r : " << r << "; d: " << d << std::endl;
				flag = true;
				break;
			}
		}
		if (flag) {
			//std::map<int, int> *it = a.find(c);
			a.erase(c);
			a[l] = d;
		}
		if (!flag) {
			//std::cout << "sdsdfsdfsd" << std::endl;
			//std::cout << "l: " << l << "; r: " << r << std::endl;
			a[l] = r;
		}
	}
	int m = a.size();
	std::cout << m << std::endl;
	for (auto k : a) {
		std::cout << k.first << " ";// << k.second << std::endl;
	}
	std::cout << std::endl;
	return 0;
}

#endif // ALGO_4_1_1_H

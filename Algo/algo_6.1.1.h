#ifndef ALGO_6_1_1_H
#define ALGO_6_1_1_H

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

int get_pos(const std::vector<int> &numbers, int number) {
	int l = 0;
	int r = numbers.size() - 1;
	while (l != r) {
		int k = (l + r) / 2;
		if (r == l + 1) {
			if (numbers[l] == number) {
				return l + 1;
			}
			if (numbers[r] == number) {
				return r + 1;
			}
			return -1;
		}
		int num = numbers[k];
		if (num == number) {
			return k + 1;
		}
		else {
			if (num < number) {
				l = k;
			}
			else {
				r = k;
			}
		}
	}

}

int algo611() {
	size_t number_count;
	std::cin >> number_count;
	std::vector<int> numbers(number_count);
	for (auto &number:numbers) {
		std::cin >> number;
	}
	assert(std::is_sorted(numbers.begin(), numbers.end()));

	size_t query_count;
	std::cin >> query_count;
	while (query_count-- > 0) {
		int number;
		std::cin >> number;
		std::cout << get_pos(numbers, number) << " ";
	}
	std::cout << std::endl;
}


#endif // ALGO_6_1_1_H

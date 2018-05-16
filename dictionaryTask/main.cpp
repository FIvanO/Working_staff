#include <iostream>
#include <cstdio>
#include <map>

typedef long long LL;

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::map;

int letterW(char l) { // calculate weight for every letter
	return int(l - 'A') + 1;
}

LL calculateDictionary(const string &input) {
	map<string, int> weidth; // weidth for every word
	int l = input.length();

	bool start = false; // should be true, when we start reading the next word, else false
	string word = ""; // for making word from input string
	int weidth_ = 0; // for calculating weidth for each word
	for (int i = 0; i < l; ++i) {
		if (input[i] == '\"') { // if we read a " we changing our state (variable start)
			if (!start) { // it will be a new word
				start = true;
				continue;
			}
			else { // end of word
				start = false;
				weidth[word] = weidth_; // saving data
				word = "";
				weidth_ = 0;
			}
		}

		if (start) { // our state is reading a word (start = true)
			word += input[i]; // making a word
			weidth_ += letterW(input[i]); // calculating weidth of word
		}
	}

	int k = 1; // position in dictionary
	LL ans = 0; // sum of all weidth
	for (auto i = weidth.begin(); i != weidth.end(); ++i) {
		cout << i->first << ": " << i->second * k << endl;
		ans += i->second * k;
		k++;
	}
	return ans;
}

int main()
{
	freopen("../Input.txt", "r", stdin); // for reading our input string

	string s;
	getline(cin, s); // must to use getline because of empty symbols
	cout << calculateDictionary(s) << endl;
	return 0;
}

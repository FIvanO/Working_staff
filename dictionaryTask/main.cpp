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

LL calculateDictionary(const string &inputFile) {
	string input = "../" + inputFile;
	freopen(input.c_str(), "r", stdin); // for reading our input string
	map<string, int> weidth; // weidth for every word

	char c;
	bool start = false; // should be true, when we start reading the next word, else false
	string word = ""; // for making word from input string
	int weidth_ = 0; // for calculating weidth for each word
	while (cin >> c) {
		if (c == '\"') { // if we read a " we changing our state (variable start)
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
			word += c; // making a word
			weidth_ += letterW(c); // calculating weidth of word
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
	string inputFile = "Input.txt"; // input file name, should be in the folder with project folder
	cout << calculateDictionary(inputFile) << endl;
	return 0;
}

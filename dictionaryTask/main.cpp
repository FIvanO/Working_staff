#include <iostream>
#include <fstream>
#include <cstdio>
#include <map>

typedef long long LL;

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::ifstream;

// set ifstream for input file or throwing exception, if file name incorrect or doesn't exist
void setFileStream(const string &inputFile, ifstream &fIn) {
	string input = "../" + inputFile;
	fIn = ifstream(input);
	if (!fIn.is_open()) {
		throw ("File name incorrect");
	}
}

// calculate weight for every letter
int letterW(char l) {
	return int(l - 'A') + 1;
}

// fulling array with weidth for every word
void calculateWordWeidth(map<string, int> &weidth, ifstream &fInput) {
	char c;
	bool start = false; // should be true, when we start reading the next word, else false
	string word = ""; // for making word from input string
	int weidth_ = 0; // for calculating weidth for each word
	while (fInput >> c) {
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
}

// calcuate final weidth taking into consideration the position of each word in alphabetical order
LL getFinalWeidth(map<string, int> &weidth) {
	int k = 1; // position in dictionary
	LL ans = 0; // sum of all weidth
	for (auto i = weidth.begin(); i != weidth.end(); ++i) {
		ans += i->second * k;
		k++;
	}
	return ans;
}

// control function
LL calculateDictionary(const string &inputFile) {
	ifstream fInput;
	try {
		setFileStream(inputFile, fInput);
	}
	catch (const char *ex) {
		cout << ex << endl;
		return -1;
	}
	map<string, int> weidth; // weidth for every word
	calculateWordWeidth(weidth, fInput);
	fInput.close();
	return getFinalWeidth(weidth);
}

int main()
{
	string inputFile = "names.txt"; // input file name, should be in the folder with project folder
	cout << calculateDictionary(inputFile) << endl;
	return 0;
}

#include <iostream>
#include <vector>
#include <numeric>
#include <random>
#include <algorithm>
#include <time.h>
#include <map>

const int N = 100;
const int del_sym = 8;
const int per = 10;

using std::cin;
using std::cout;
using std::endl;

void vi_pr() {
    std::vector <int> vi;
    for (int i = 0; i < N; ++i) {
        vi.push_back(rand() % per);
    }

    cout << "Before:" << endl;
    for (int i = 0; i < vi.size(); ++i) {
        cout << vi[i] << " ";
    }
    cout << endl;

    vi.erase( std::remove(vi.begin(), vi.end(), del_sym), vi.end() );

    cout << "After: " << endl;
    for (auto i : vi) {
        cout << i << " ";
    }
    cout << endl;


}

void map_pr() {
    std::map <int, int> m;
    std::vector <int> vi;
    for (int i = 0; i < N; ++i) {
        m[i] = rand() % per;
    }
    cout << "Before: " << endl;
    for (auto k : m) {
        cout << k.second << " ";
    }
    cout << endl;

    for (auto k : m) {
        if (k.second == del_sym) {
            vi.push_back(k.first);
        }
    }
    for (auto k : vi) {
        m.erase(k);
    }

    cout << "After: " << endl;
    for (auto k : m) {
        cout << k.second << " ";
    }
}

int task() {
    srand(time(NULL));
    cout << "vector: " << endl;
    vi_pr();
    cout << "---------------------" << endl;
    cout << "map: " << endl;
    map_pr();
    return 0;
}

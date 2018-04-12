#include <cassert>
#include <cstdint>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int algo_413() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        cout << 1 << endl;
        return 0;
    }
    if (n == 2) {
        cout << 1 << endl;
        cout << 2 << endl;
        return 0;
    }
    if (n == 3) {
        cout << 2 << endl;
        cout << "1 2" << endl;
        return 0;
    }
    int res = 0;
    int k = 0;
    for (int i = 1; i < n; ++i) {
        res += i;
        k++;
        if (res > n) {
            int r = res - n;
//            cout << "r: " << r << endl;
//            cout << "k: " << k << endl;
            cout << "res: " << res << endl;
            cout << k - 1 << endl;
            for (int j = 1; j <= k; ++j) {
                if (j != r) {
                    cout << j << " ";
                }
            }
            cout << endl;
            break;
        }
    }

    return 0;
}

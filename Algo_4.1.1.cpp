#include <iostream>
#include <utility>
#include <map>

int main(void) {
  int n;
  std::cin >> n;
  std::map <int, int> a;
  //std::map <int, int> b;
    
    for (int i = 0; i < n; ++i) {
        int l, r;
        bool flag = false;
        int c, d;
        std::cin >> l >> r;
        for (auto k = a.begin(); k != a.end(); ++k) {
            if (k -> first <= l && l <= k -> second) {
                //k -> first = l;
                c = k -> first;
                d = std::min(k -> second, r);
                flag = true;
                break;
            } 
        }
        if (flag) {
            //std::map<int, int> *it = a.find(c);
            a.erase(c);
            a[l] = d;
        }
        if (!flag) a[l] = r;
    }
    int m = a.size();
    std::cout << m << std::endl;
    for (auto k : a) {
        std::cout << k.first << " ";//<< k.second << std::endl;
    }
    std::cout << std::endl;
}

#include <cassert>
#include <cstdint>
#include <iostream>
#include <string>
#include <map>
#define mp(x, y) std::make_pair(x, y)

using std::cin;
using std::cout;
using std::endl;
using std::string;

struct H_tree {
    H_tree(HString *_h) : sheet(false), Hstr(_h) {}
    H_tree(char _c) : c(_c), sheet(true) {}
    string getHCode(char _c);
    H_tree *l_son;
    H_tree *r_son;
    HString *Hstr;
    char c;
    bool sheet;
};

struct HString {
    HString() : prew(NULL), next(NULL) {}
    string s1;
    string s2;
    HString *prew;
    HString *next;
};

int algo_421() {
    string s, ss;
    cin >> ss;
    int l = ss.length();
    auto comp = [](const int& a, const int& b) { return a < b; };
    std::multimap <int, string, decltype(comp)> mm(comp);
    std::map <char, int> a;
    std::map <char, string> H;

    for (int i = 0; i < l; ++i) {
        a[ss[i]]++;
    }
    for (auto k : a) {
        mm.insert(mp(k.second, std::to_string(k.first)));
    }

    HString* h = new HString;
    int nn = mm.size();
    for (int i = 0; i < nn - 1; ++i) {
        while (h -> next != NULL) {
            h = h -> prew;
        }
        h -> next = new HString;
        h -> next -> prew = h;
        auto k = mm.begin();
        h->s1 = k->second;
        int sm1 = k->first;
        k++;
        int sm2 = k->first;
        h->s2 = k->second;
        mm.erase(sm1);
        mm.erase(sm2);
        mm.insert(mp(sm1 + sm2, h->s1 + h->s2));
    }

    H_tree *Htr = new H_tree(h);
//    while (!Htr->sheet) {
    for (int i = 0; i < 10*nn; ++i) {
        int l1 = Htr->Hstr->s1.length();
        int l2 = Htr->Hstr->s2.length();
        if (l1 != 1) {
            Htr->l_son = new H_tree(Htr->Hstr->prew);
            while (Htr->l_son->Hstr->s1.find(Htr->Hstr->s1[0]) == -1 && Htr->l_son->Hstr->s2.find(Htr->Hstr->s1[0]) == -1) {
                Htr->l_son->Hstr = Htr->l_son->Hstr->prew;
            }
        } else {
            Htr->l_son = new H_tree(Htr->Hstr->s1[0]);
            Htr->r_son = new H_tree(Htr->Hstr->s2[0]);
        }

        if (l2 != 1) {
            Htr->r_son = new H_tree(Htr->Hstr->prew);
            while (Htr->r_son->Hstr->s1.find(Htr->Hstr->s1[0]) == -1 && Htr->r_son->Hstr->s2.find(Htr->Hstr->s1[0]) == -1) {
                Htr->r_son->Hstr = Htr->r_son->Hstr->prew;
            }
        } else {
            Htr->l_son = new H_tree(Htr->Hstr->s1[0]);
            Htr->r_son = new H_tree(Htr->Hstr->s2[0]);
        }
    }


/*
    s = "0";
    for (auto k : mm) {
        H[k.second] = s;
        s = '1' + s;
    }
    if (a.size() > 1) {
        s.erase(s.length() - 2, 2);
        auto k = mm.end();
        k--;
        H[k -> second] = s;
    }

    s = "";
    for (int i = 0; i < l; ++i) {
        s += H[ss[i]];
    }
    cout << a.size() << " " << s.length() << endl;
    for (auto k : H) {
        cout << k.first << ": " << k.second << endl;
    }
    cout << s << endl; */
    return 0;
}

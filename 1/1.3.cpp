#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Count(const string &a, int cnt[]) {
    for (int i = 0; i < a.size(); ++i) {
        ++ cnt[a[i]];
    }
}

bool IsPerm(const string &a, const string &b) {
    int cnta[256] = {0}, cntb[256] = {0};
    Count(a, cnta);
    Count(b, cntb);
    for (int i = 0; i < 256; ++i) {
        if (cnta[i] != cntb[i]) return false;
    }
    return true;
}

int main() {
    vector<pair<string,string> > cases = {
        { "", "" },
        { "", "abc" },
        { "abc", "abc" },
        { "ab", "ba"} , 
        { "aa", "bb"} };
    for (int i = 0; i < cases.size(); ++i) {
        cout << IsPerm(cases[i].first, cases[i].second) << endl;
    }
    return 0;
}

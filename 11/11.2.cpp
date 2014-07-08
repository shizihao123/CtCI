#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool byAnagrams(const string &a, const string &b) {
    int cnt[26] = {0};
    for (int i = 0; i < a.size(); ++i) {
        ++ cnt[a[i] - 'a'];
    }
    for (int i = 0; i < b.size(); ++i) {
        -- cnt[b[i] - 'a'];
    }
    for (int i = 0; i < 26; ++i) {
        if (cnt[i] != 0) return cnt[i] > 0;
    }
    return false;
}

int main() {
    vector<string> strs = {"abc", "aab", "bab", "acb", "acb", "baa"};
    sort(strs.begin(), strs.end(), byAnagrams);
    for (int i = 0; i < strs.size(); ++i) {
        cout << strs[i] << " ";
    }
    cout << endl;
    return 0;
}
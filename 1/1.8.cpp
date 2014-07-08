#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

bool IsSubstring(const string &a, const string &b) {
    return a.find(b) != string::npos;
}

bool IsRotation(const string &a, const string &b) {
    if (a.size() != b.size()) return false;
    return IsSubstring(a + a, b);
}

int main() {

    // string testcase[][2] = {
    vector<pair<string, string> > cases = {
        { "", ""} ,
        { "a", "a"} ,
        { "a", "aa"} ,
        { "abc", "abc"} ,
        { "abc", "cba"} ,
        { "abc", "cab" }
    };
    for (int i = 0; i < cases.size(); ++i) {
        cout << IsRotation(cases[i].first, cases[i].second) << endl;
    }
    return 0;
}

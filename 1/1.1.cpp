#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool IsUniqueLetter(const string &str) {
    int check = 0;
    for (int i = 0; i < str.size(); ++i) {
        if ('a' <= str[i] && str[i] <= 'z') {
            if (check & (1<<(str[i] - 'a'))) return false;
            check |= 1<<(str[i] - 'a');
        }
    }
    return true;
}

bool IsUniqueASCII(const string &str) {
    bool check[256] = {false};
    for (int i = 0; i < str.size(); ++i) {
        if (check[str[i]]) return false;
        check[str[i]] = true;
    }
    return true;
}

int main() {
    vector<string> cases = {"", "aA", "  a", "check", "Interview"};
    for (size_t i = 0; i < cases.size(); ++i) {
        cout << IsUniqueLetter(cases[i]) << " " 
             << IsUniqueASCII(cases[i]) << endl;
    }
    return 0;
}

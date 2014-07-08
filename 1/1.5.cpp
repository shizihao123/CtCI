#include <iostream>
#include <string>
#include <vector>

using namespace std;

string I2string(int x) {
    char c_str[12];
    sprintf(c_str, "%d", x);
    return string(c_str);
}

string Compression(const string &str) {
    string encode;
    if (str.size() <= 2) return str;
    int cnt = 1;
    for (int i = 1; i < str.size(); ++i) {
        if (str[i] != str[i - 1]) {
            encode += str[i - 1];
            encode += I2string(cnt);
            cnt = 0;
        }
        ++ cnt;
    }
    encode += str[str.size() - 1];
    encode += I2string(cnt);
    return encode.size() < str.size()? encode:string(str);
}

int main() {
    vector<string> cases = {"", "a", "aa", "aaaaaaaa", "aaaabbaaaaaba", "    "};
    for (int i = 0; i < cases.size(); ++i) {
        cout << Compression(cases[i]) << endl;
    }
    return 0;
}

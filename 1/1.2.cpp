#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void reverse(char *str) {
    int len = strlen(str);
    char temp;
    for (int i = 0; i < (len>>1); ++i) {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int main() {
    vector<char*> cases = { "", "a", "ab", "abc", "abcd" };
    char p[10];
    for (int i = 0; i < cases.size(); ++i) {
        strcpy(p, cases[i]);
        reverse(p);
        cout << p << endl;
    }
    return 0;
}

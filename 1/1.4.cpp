#include <iostream>
#include <string>

using namespace std;

void Replace(char str[], int len) {
    int cnt_space = 0;
    for (int i = 0; i < len; ++i) {
        if (str[i] == ' ') ++ cnt_space;
    }
    str[len + cnt_space * 2] = 0;
    for (int i = len - 1, index = len + cnt_space * 2; i >= 0; --i) {
        if (str[i] == ' ') {
            str[--index] = '0';
            str[--index] = '2';
            str[--index] = '%';
        } else {
            str[--index] = str[i];
        }
    }
}

int main() {
    string input;
    getline(cin, input);
    char* str = new char[input.size() * 3 + 1];
    strcpy(str, input.c_str());
    Replace(str, input.size());
    cout << str << endl;
    delete[] str;
    return 0;
}
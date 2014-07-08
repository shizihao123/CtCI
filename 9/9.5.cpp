#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void PrintAllPermutationOfString(string str) {
    sort(str.begin(), str.end());
    do {
        cout << str << endl;
    } while (next_permutation(str.begin(), str.end()));
}

int main() {
    PrintAllPermutationOfString("abcaaa");
    return 0;
}
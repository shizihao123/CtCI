#include <iostream>

using namespace std;

int GetBitsChange(int x, int y) {
    x ^= y;
    int cnt = 0;
    while (x) {
        ++ cnt;
        x ^= (x & -x);
    }
    return cnt;
}

int main() {
    cout << GetBitsChange(31, 14) << endl;
    return 0;    
}
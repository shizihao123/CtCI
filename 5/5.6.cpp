#include <iostream>
#include <cstdio>

using namespace std;

int SwapOddEvenBits(int x) {
    static int mask = 0x55555555;
    return ((x >> 1) & mask) | ((x << 1) & (mask << 1));
}

int main() {
    cout << SwapOddEvenBits(0x1b) << endl;
    return 0;    
}
#include <cstdio>

int InsertM2N(int n, int m, int i, int j) {
    return ((n >> j) << j) | (m << i) | (n & ((1<<i) - 1));
}

int main() {
    int n = 0x400;
    int m = 0x13;
    printf("%x\n", InsertM2N(n, m, 2, 6));
    return 0;
}
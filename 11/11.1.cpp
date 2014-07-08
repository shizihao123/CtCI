#include <iostream>

int meger(int a[], int n, int b[], int m) {
    int p = n, q = m;
    while (q) {
        if (a[p - 1] > b[q - 1]) a[p + q] = a[--p];
        else a[p + q] = b[--q];
    }
    return n + m;
}

int main() {
    int a[10] = {1, 3, 4, 5}, na = 4, b[] = {2, 3, 7}, nb = 3;
    meger(a, na, b, nb);
    for (int i = 0; i < na + nb; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
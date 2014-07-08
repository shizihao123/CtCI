#include <iostream>

void check(int a[], int n, int &left, int &right) {
    left = 0, right = n - 1;
    while (left < n - 1 && a[left] <= a[left + 1]) ++ left;
    while (0 < right && a[right - 1] <= a[right]) -- right;
    if (left > right) {
        left = right = -1;
        return ;
    }
    int minx = a[left], maxx = a[right];
    for (int i = left; i <= right; ++i) {
        minx = std::min(minx, a[i]);
        maxx = std::max(maxx, a[i]);
    }
    while (left >= 0 && a[left] > minx) --left;
    while (right < n && a[right] < maxx) ++right;
    ++ left, --right;
}

int main(int argc, char *argv[]) {
    int a[] = {
        1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19
    }, left, right;
    check(a, 13, left, right);
    std::cout << left << " " << right << std::endl;
    return 0;
}

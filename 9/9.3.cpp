#include <iostream>
#include <cassert>

using namespace std;

int FindMagicIndex(int a[], int n) {
    int left = 0, right = n - 1;
    while (left < right) {
        int mid = (left + right) / 2;
        if (a[mid] == mid) return mid;
        if (a[mid] > mid) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int main() {
    int x, y;
    cin >> x >> y;
    cout << solve1(x, y) << endl;
    return 0;
}
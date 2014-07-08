#include <iostream>

using namespace std;

int find(int a[], int n, int x, int first = 0) {
    int left = first, right = n - 1 + first;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (a[mid % n] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return a[left % n] == x? left % n: -1;
}

int FindPivotUnique(int a[], int n) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) >> 1;
        if (a[0] < a[mid]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

int FindUnique(int a[], int n, int x) {
    int pivot = FindPivotUnique(a, n);
    cout << pivot << endl;
    return find(a, n, x, pivot);
}

int main() {
    int a[12] = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
    cout << FindUnique(a, 12, 5) << endl;
    return 0;
}


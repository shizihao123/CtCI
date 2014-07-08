#include <iostream>

int MaxSumOfSubsequence(int a[], int n) {
    int maxsum = 0, sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        if (sum < 0) sum = 0;
        maxsum = std::max(maxsum, sum);
    }
    return maxsum;
}

int main(int argc, char *argv[]) {
    int a[] = { 2, -8, 3, -2, 4, -10 };
    std::cout << MaxSumOfSubsequence(a, 6) << std::endl;
    return 0;
}

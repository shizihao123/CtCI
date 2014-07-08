#include <iostream>
#include <vector>

using namespace std;

int GetNextSmallest(int x) {
    int y = x;
    if (x & 1) {
        int cnt1 = 0, cnt0 = 0;
        while (x & 1) {
            ++ cnt1;
            x >>= 1;
        }
        if (x == 0) return -1;
        while ((x & 1) == 0) {
            x >>= 1;
            ++ cnt0;
        }
        return (y >> (cnt0 + cnt1 + 1) << (cnt0 + cnt1 + 1)) | 
               (((1<<(cnt1 + 1)) - 1)<<(cnt0 - 1));
    } else {
        int p = 1;
        while ((x & 1) == 0) {
            x >>= 1;
            p <<= 1;
        }
        return (y ^ p) | (p>>1);
    }
    return x;
}

int GetNextLargest(int x) {
    int p = 1, cnt = 0, y = x;
    while ((x & 1) == 0) {
        x >>= 1;
        p <<= 1;
    }
    while ((x & 1)) {
        x >>= 1;
        ++ cnt;
    }
    return (y + p) | ((1<<(cnt-1)) - 1);
}

int main() {
    vector<int> cases = { 5, 7, 13, 105, 1000, 12345 };
    for (int i = 0; i < cases.size(); ++i) {
        cout << "x=" << cases[i] << ", smallest=" << GetNextSmallest(cases[i]) 
             << ", largest=" << GetNextLargest(cases[i]) << endl;
    }
    return 0;
}

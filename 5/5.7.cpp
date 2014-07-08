#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

inline int fetch(int x, int k) {
    return (x & 1<<k);
}

int FindMissing(vector <int> &arry, int col = 0) {
    assert(0 <= col && col <= 32);
    if (arry.size() == 0) return 0;
    vector<int> odd, even;
    for (int i = 0; i < arry.size(); ++i) {
        if (fetch(arry[i], col) == 0)  even.push_back(arry[i]);
        else odd.push_back(arry[i]);
    }
    if (even.size() > odd.size()) return FindMissing(odd, col + 1) << 1 | 1;
    else return FindMissing(even, col + 1) << 1 | 0;
}

int main() {
    std::vector<int> vec;
    for (int i = 0; i < 100; ++i) {
        if (i != 99) vec.push_back(i);
    }
    cout << FindMissing(vec) << endl;
    return 0;
}
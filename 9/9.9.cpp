#include <iostream>

using namespace std;

void DFS(int k, int n, int left, int right, int top, int step[]) {
    if (k == n) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (step[i] == j) {
                    cout << "*";
                } else {
                    cout << ".";
                }
            }
            cout << endl;
        }
        cout << endl;
        return ;
    }
    for (int i = 0; i < n; ++i) {
        if ((1<<i & left) || (1<<i & right) || (1<<i & top)) {
            continue;
        }
        step[k] = i;
        DFS(k + 1, n, (left | 1<<i) << 1, (right | 1<<i) >> 1, top | 1<<i, step);
    }
}

void queen(int n) {
    if (n >= 32 || n < 0) return ;
    int step[n];
    DFS(0, n, 0, 0, 0, step);
}

int main() {
    queen(4);
    return 0;
}

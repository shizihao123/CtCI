#include <iostream>

using namespace std;

typedef long long LL;

LL solve(int n) {
    if (n <= 1) return 1;
    if (n == 2) return 2;
    LL *f = new LL(n + 1), ans;
    f[0] = 1, f[1] = 1, f[2] = 2;
    for (int i = 3; i <= n; ++i) {
        f[i] = f[i - 1] + f[i - 2] + f[i - 3];
    }
    ans = f[n];
    delete [] f;
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << solve(n) << endl;
}
#include <iostream>
#include <vector>

using namespace std;

int solve(int n) {
    if (n < 0) throw std::string("n < 0");
    std::vector<int> f(n + 1, 0);
    f[0] = 1;
    std::vector<int> coin = {1, 5, 10, 25};
    for (int i = 0; i < coin.size(); ++i) {
        for (int j = 1; j <= n; ++j) {
            if (j >= coin[i]) {
                f[j] += f[j - coin[i]];
            }
        }
    }
    return f[n];
}

int main() {
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}


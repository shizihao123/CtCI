#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

typedef long long LL;

LL solve1(int x, int y) {
    assert(x > 0 && y > 0);
    LL c = 1;
    for (int i = 1; i <= x; ++i) {
        c = c * (x + y - i + 1) / i;
    }
    return c;
}

LL solve2(int x, int y, const vector<vector<bool> >&block) {
    vector<vector<LL> > f(x + 1, vector<LL>(y + 1, 0));
    f[0][0] = 1;
    for (int i = 1; i <= x; ++i) {
        if (block[i][0]) f[i][0] = 0;
        else f[i][0] = f[i - 1][0];
    }
    for (int j = 1; j <= y; ++j) {
        if (block[0][j]) f[0][j] = 0;
        else f[0][j] = f[0][j - 1];
    }
    for (int i = 1; i <= x; ++i) {
        for (int j = 1; j <= y; ++j) {
            if (block[i][j]) f[i][j] = 0;
            else f[i][j] = f[i - 1][j] + f[i][j - 1];
        }
    }
    return f[x][y];
}

int main() {
    int x, y;
    cin >> x >> y;
    cout << solve1(x, y) << endl;
    return 0;
}
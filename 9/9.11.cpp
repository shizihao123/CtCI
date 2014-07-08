#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string expre;
    cin >> expre;
    int n = (expre.size() + 1) / 2;
    vector<vector<int> > f0(n, vector<int>(n, 0));
    vector<vector<int> > f1(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        if (expre[i * 2] == '0') {
            f0[i][i] = 1;
        } else {
            f1[i][i] = 1;
        }
    }
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i + len <= n; ++i) {
            int j = i + len - 1;
            for (int k = i; k < j; ++k) {
                switch(expre[k * 2 + 1]) {
                    case '&':
                        f1[i][j] += f1[i][k] * f1[k + 1][j];
                        f0[i][j] += f1[i][k] * f0[k + 1][j] 
                            + f0[i][k] * f1[k + 1][j]
                            + f0[i][k] * f0[k + 1][j];
                        break;
                    case '|':
                        f1[i][j] += 
                            + f1[i][k] * f1[k + 1][j]
                            + f1[i][k] * f0[k + 1][j] 
                            + f0[i][k] * f1[k + 1][j];
                        f0[i][j] += f0[i][k] * f0[k + 1][j];
                        break;
                    case '^':
                        f1[i][j] += f0[i][k] * f1[k + 1][j]
                            + f1[i][k] * f0[k + 1][j];
                        f0[i][j] += f1[i][k] * f1[k + 1][j]
                            + f0[i][k] * f0[k + 1][j];
                        break;
                    default:
                        cout << k * 2 + 1 << " error" << endl;
                }
            }
        }
    }
    cout << f1[0][n - 1] << " " << f0[0][n - 1] << endl;
    return 0;
}


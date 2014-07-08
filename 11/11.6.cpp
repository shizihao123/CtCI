#include <iostream>
#include <vector>

using namespace std;

pair<int, int> Find(vector<vector<int> >&matrix, int value) {
    int n = matrix.size();
    if (n == 0) return make_pair(-1, -1);
    int m = matrix[0].size();
    if (m == 0) return make_pair(-1, -1);
    int x = 0, y = m - 1;
    while (x < n && y >= 0) {
        if (matrix[x][y] == value) {
            return make_pair(x, y);
        }
        if (matrix[x][y] < value) {
            ++ x;
        } else {
            -- y;
        }
    }
    return make_pair(-1, -1);
}

int main() {
    vector<vector<int> > matrix = {{0, 1, 2}, {2, 3, 5}, {4, 6, 8}};
    int value;
    cin >> value;
    pair<int, int> result = Find(matrix, value);
    cout << result.first << " " << result.second << endl;
    return 0;
}


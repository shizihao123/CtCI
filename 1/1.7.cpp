#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

void SpreadZero(vector<vector<int> > &matrix) {
    int n = matrix.size();
    if (0 == n) return;
    int m = matrix[0].size();
    vector<bool> row_zero(n, false), col_zero(m, false);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == 0) {
                row_zero[i] = col_zero[j] = true;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (row_zero[i] || col_zero[j]) {
                matrix[i][j] = 0;
            }
        }
    }
}

void OutputMatrix(const vector<vector<int> > &matrix) {
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            printf("%3d", matrix[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int n = 5;
    vector<vector<int> > matrix;
    for (int i = 0; i < n; ++i) {
        vector<int> line;
        for (int j = 0; j < n; ++j) {
            line.push_back(rand() % 10? 1: 0);
        }
        matrix.push_back(line);
    }
    OutputMatrix(matrix);
    SpreadZero(matrix);
    OutputMatrix(matrix);
    return 0;
}
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

void Rotate90(vector<vector<int> > &matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        if (matrix[i].size() != n) return ;
    }
    for (int i = 0; i < n / 2; ++i) {
        for (int j = i; j < n - i - 1; ++j) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[n - j - 1][i];
            matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
            matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
            matrix[j][n - i - 1] = temp;
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
            line.push_back(i * n + j);
        }
        matrix.push_back(line);
    }
    OutputMatrix(matrix);
    Rotate90(matrix);
    OutputMatrix(matrix);
    return 0;
}
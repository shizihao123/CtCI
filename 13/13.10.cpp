#include <iostream>
#include <cassert>

template <class T>
T **malloc_matrix(int x, int y) {
    assert(x > 0 && y > 0);
    T ** matrix = (T **)malloc(x * sizeof (T*));
    for (int i = 0; i < x; ++i) {
        matrix[i] = (T*)malloc(y * sizeof(T));
    }
    return matrix;
}

int main(int argc, char *argv[]) {
    int ** matrix = malloc_matrix<int>(4, 4);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            matrix[i][j] = i * 4 + j;
        }
    }
    for (int i = 0; i < 4; ++i) std::cout << matrix[i][i] << std::endl;
    return 0;
}

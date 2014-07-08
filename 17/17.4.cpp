#include <iostream>
#include <vector>

// when >= 0 return 0, otherwise return -1
inline int sign(int x) {
    return (x >> (sizeof(int) * 8 - 1));
}

int max(int x, int y) {
    // when sign of x and sign of y are the same sign_same=0
    // otherwise sign_same=-1
    int sign_same = sign(x) ^ sign(y);
    int k = (sign(x - y) & ~sign_same) | (sign(x) & sign_same);
    return (1 + k) * x - k * y;
}

int main(int argc, char *argv[]) {
    std::vector<std::pair<int,int> > cases = {
        {0, 0},
        {12, 4},
        {3, 9},
        {-1, 23},
        {2, -100},
        {2147483646, 2147483647},
        {-2147483648, 2137483647},
        {-2147483647, -2147483648} };
    for (int i = 0; i < cases.size(); ++i) {
        std::cout << "max of (" << cases[i].first << ", " << cases[i].second << ") is " << 
            max(cases[i].first, cases[i].second) << std::endl;
    }
    return 0;
}

#include <iostream>
#include <vector>

int swap(int &x, int &y) {
    x ^= y ^= x ^= y;
}

int main(int argc, char *argv[]) {
    std::vector<std::pair<int, int> > cases = {
        {0, 0},
        {3, 7},
        {-1, 10},
        {-8, -10},
        {2147483647, -2147483648} };
    for (int i = 0; i < cases.size(); ++i) {
        std::cout << "before swap: " << cases[i].first << " " << cases[i].second << std::endl;
        swap(cases[i].first, cases[i].second);
        std::cout << "after swap: " << cases[i].first << " " << cases[i].second << std::endl;
    }
    return 0;
}

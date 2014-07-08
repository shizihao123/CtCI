#include <iostream>
#include <string>

using namespace std;

void DFS(int left, int right, std::string pairs) {
    if (left == 0 && right == 0) {
        std::cout << pairs << std::endl;
    }
    if (left > 0) {
        pairs.push_back('(');
        DFS(left - 1, right, pairs);
        pairs.pop_back();
    }
    if (left != right) {
        pairs.push_back(')');
        DFS(left, right - 1, pairs);
        pairs.pop_back();
    }
}

void PrintNPairs(int n) {
    std::string pairs;
    DFS(n, n, pairs);
}

int main() {
    int n;
    std::cin >> n;
    PrintNPairs(n);
    return 0;
}

#include <iostream>
#include <stack>

using namespace std;

struct Problem {
    char from, to, temp;
    int largest, n;
    Problem(int n, int largest, char from = 'A', char to = 'C', char temp = 'B')
    : n(n), largest(largest), from(from), to(to), temp(temp) {}
};

void ShowMove(int n, char from, char to) {
    cout << " move " << n << ": " << from << " -> " << to << endl;
}

void Solve(int n) {
    if (n <= 0) return ;
    stack<Problem> problem_set;
    problem_set.push(Problem(n, n));
    while (!problem_set.empty()) {
        Problem p = problem_set.top();
        problem_set.pop();
        if (p.n == 1) ShowMove(p.largest, p.from, p.to);
        else {
            problem_set.push(Problem(p.n - 1, p.largest - 1, p.temp, p.to, p.from));
            problem_set.push(Problem(1, p.largest, p.from, p.to, p.temp));
            problem_set.push(Problem(p.n - 1, p.largest - 1, p.from, p.temp, p.to));
        }
    }
}

int main() {
    cout << endl << "check n = 0" << endl;
    Solve(0);
    cout << endl << "check n = 1" << endl;
    Solve(1);
    cout << endl << "check n = 2" << endl;
    Solve(2);
    cout << endl << "check n = 4" << endl;
    Solve(4);
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

const double eps = 1e-8;

string Binary(double x) {
    string bin = ".";
    while (x > eps && bin.size() < 32) {
        x = x * 2;
        if (x >= 1) {
            bin += '1';
            x -= 1;
        } else {
            bin += '0';
        }
    }
    if (x > eps) return "ERROR";
    else return bin;
}

int main() {
    vector<double> cases = {0.15, 0.5, 0.72, 0.75, 0.125, 0.0725};
    for (int i = 0; i < cases.size(); ++i) {
        cout << Binary(cases[i]) << endl;
    }
    return 0;
}

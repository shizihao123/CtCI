#include <iostream>
#include <vector>

using namespace std;

int FindNext(vector<string> &strvec, int idx) {
    while (idx < strvec.size() && strvec[idx] == "") ++ idx;
    return idx;
}

int FindPre(vector<string> &strvec, int idx) {
    while (idx >= 0 && strvec[idx] == "") -- idx;
    return idx;
}

int Find(vector<string> &strvec, string str) {
    int left = FindNext(strvec, 0);
    int right = FindPre(strvec, strvec.size());
    while (left <= right) {
        // cout << left << " " << right << endl;
        int mid = FindNext(strvec, (left + right) / 2);
        if (strvec[mid] < str) {
            left = FindNext(strvec, mid + 1);
        } else {
            right = FindPre(strvec, mid - 1);
        }
    }
    return strvec[left] == str? left: -1;
}


int main() {
    vector<string> strvec = {"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
    string vec;
    cin >> vec;
    cout << Find(strvec, vec) << endl;
    return 0;
}


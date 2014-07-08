#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(const vector<int> &set_, int k, vector<vector<int> >&subset, vector<int>& now) {
    if (k == set_.size()) {
        subset.push_back(now);
        return ;
    }
    DFS(set_, k + 1, subset, now);
    now.push_back(set_[k]);
    DFS(set_, k + 1, subset, now);
    now.pop_back();
}

void FindAllSubset(vector<int> &set_, vector<vector<int> >&subset) {
    sort(set_.begin(), set_.end());
    set_.erase(unique(set_.begin(), set_.end()), set_.end());
    std::vector<int> now;
    DFS(set_, 0, subset, now);
}

int main() {
    vector<int> vec = {1, 2, 3, 4, 3 ,2};
    vector<vector<int> > subset;
    FindAllSubset(vec, subset);
    for (int i = 0; i < subset.size(); ++i) {
        for (int j = 0; j < subset[i].size(); ++j) {
            cout << subset[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

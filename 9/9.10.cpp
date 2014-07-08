#include <iostream>
#include <vector>

using namespace std;

struct Box {
    int width, height, depth;
    bool operator< (const Box &that) const {
        return width < that.width && height < that.height && depth < that.depth;
    }
};

istream & operator >> (istream &is, Box &box) {
    is >> box.width >> box.height >> box.depth;
    return is;
}

int DFS(vector<Box> &boxes, vector<int> &sum, int k) {
    if (sum[k]) return sum[k];
    int mx = 0;
    for (int i = 0; i < boxes.size(); ++i) {
        if (boxes[i] < boxes[k]) {
            mx = std::max(DFS(boxes, sum, i), mx);
        }
    }
    sum[k] = mx + boxes[k].depth;
    return sum[k];
}

int main() {
    int n;
    cin >> n;
    vector<Box> boxes(n);
    vector<int> sum(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> boxes[i];
    }
    int result = 0;
    for (int i = 0; i < n; ++i) {
        result = max(result, DFS(boxes, sum, i));
    }
    cout << result << endl;
    return 0;
}


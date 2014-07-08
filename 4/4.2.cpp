#include <iostream>
#include <queue>
#include <cassert>
#include <vector>

using namespace std;

bool HasRoute(vector<vector<int> > &graph, int from, int to) {
    assert(0 <= from && from < graph.size());
    assert(0 <= to && to < graph.size());
    if (from == to) return true;
    vector<bool> visted(graph.size(), false);
    queue<int> openset;
    openset.push(from);
    visted[from] = true;
    while (!openset.empty()) {
        int now = openset.front();
        openset.pop();
        for (int i = 0; i < graph[now].size(); ++i) {
            if (!visted[graph[now][i]]) {
                if (graph[now][i] == to) return true;
                openset.push(graph[now][i]);
                visted[graph[now][i]] = true;
            }
        }
    }
    return false;
}
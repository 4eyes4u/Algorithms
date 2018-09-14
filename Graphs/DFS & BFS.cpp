/*
    Algorithms: Depth First Search & Breadth First Search
    Complexity: O(E + V) [where E is number of edges and V number of nodes in the graph]
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> g[N];
bool mark[N];

void dfs(int v) {
    mark[v] = 1;

    for (auto xt: g[v])
        if (!mark[xt])
            dfs(xt);
}

void bfs(int source) {
    queue<int> q;

    for (q.emplace(source), mark[source] = 1; q.size(); q.pop()) {
        int v = q.front();
        
        for (auto xt: g[v]) {
            if (mark[xt]) continue;
            
            q.emplace(xt);
            mark[xt] = 1;
        }
    }
}

int main() {

    return 0;
}

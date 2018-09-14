/*
    Name: Finding center of a tree
    
    Time complexity: O(N)
    Space complexity: O(N)s

* * *
    Additional check is needed because sub-star graph.
*/

#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;

vector<int> g[N];
int dist[N];
bool path[N];

pair<int, int> dfs(int v, int prev) {
    pair<int, int> ret = {dist[v] = dist[prev] + 1, v};

    for (auto xt : g[v])
        if (xt != prev)
        ret = max(ret, dfs(xt, v));

    return ret;
}

void make_path(int v) {
    path[v] = 1;

    for (auto xt: g[v])
        if (dist[xt] == dist[v] - 1)
            make_path(xt);
}

int find_center(int n, int d) {
    for (int i = 1; i <= n; i++)
        if (dist[i] == d && path[i])
            return i;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d%d", &u, &v);
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    dist[0] = -1;
    auto p = dfs(dfs(1, 0).second, 0);
    make_path(p.second);
    int center = find_center(n, p.first);

    return 0;
}

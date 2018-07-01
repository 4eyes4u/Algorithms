/*
    Algorithm: Finding center in a tree
    Complexity: O(V) [where V is number of nodes in the tree]

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

    for (auto xt: g[v]) {
        if (xt == prev) continue;
        ret = max(ret, dfs(xt, v));
    }

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

    for (int i = 1, a, b; i < n; i++) {
        scanf("%d%d", &a, &b);

        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    dist[0] = -1;
    pair<int, int> p = dfs(dfs(1, 0).second, 0);
    make_path(p.second);
    
    int center = find_center(n, p.first);

    return 0;
}

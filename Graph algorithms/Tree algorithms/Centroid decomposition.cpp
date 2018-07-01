/*
    Algorithm: Centroid decomposition of a tree
    Complexity: O(V * logV) [where V is number of nodes in the tree]
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> g[N], cdt[N]; // g is initial tree and cdt is centroid tree
int root, parent[N], sz[N];
bool mark[N];

int init(int v, int prev) {
    for (auto xt: g[v]) {
        if (xt == prev) continue;
        
        sz[v] += init(xt, v);
    }

    return ++sz[v];
}

int dfs(int v, int prev, int bound) {
    pair<int, int> child = {0, 0};

    for (auto xt: g[v]) {
        if (xt == prev || mark[xt]) continue;
        child = max(child, {sz[xt], xt});
    }

    if (child.first <= bound)
        return v;

    sz[v] -= child.first;
    sz[child.second] += sz[v];
    return dfs(child.second, v, bound);
}

void centroid_decomposition(int v, int prev, int bound) {
    int centroid = dfs (v, prev, bound);
    if (prev) cdt[prev].emplace_back(centroid);
    if (prev) parent[centroid] = prev;
    else root = centroid;
    mark[centroid] = 1;

    for (auto xt: g[centroid]) {
        if (mark[xt]) continue;
        centroid_decomposition(xt, centroid, (int)(sz[xt]/2));
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1, a, b; i < n; i++) {
        scanf("%d%d", &a, &b);

        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    init(1, 0);
    centroid_decomposition(1, 0, (int)(sz[1] / 2));

    return 0;
}

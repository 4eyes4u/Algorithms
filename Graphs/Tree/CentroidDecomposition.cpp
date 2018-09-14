/*
    Name: Centroid decomposition of a tree

    Time complexity: O(N * logN) for initialization
    Space complexity: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> g[N], cdt[N]; 
int root, parent[N], size[N];
bool mark[N];

int init(int v, int prev) {
    for (auto xt : g[v])
        if (xt != prev)
            size[v] += init(xt, v);

    return ++size[v];
}

int dfs(int v, int prev, int bound) {
    pair<int, int> child = {0, 0};

    for (auto xt : g[v])
        if (xt != prev && !mark[xt])
            child = max(child, {size[xt], xt});

    if (child.first <= bound)
        return v;

    size[v] -= child.first;
    size[child.second] += size[v];
    return dfs(child.second, v, bound);
}

void centroid_decomposition(int v, int prev, int bound) {
    int centroid = dfs (v, prev, bound);
    mark[centroid] = 1;
    if (prev) {
        cdt[prev].emplace_back(centroid);
        parent[centroid] = prev;
    }
    else
        root = centroid;

    for (auto xt : g[centroid])
        if (!mark[xt])
            centroid_decomposition(xt, centroid, (int)(size[xt] / 2));
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d%d", &u, &v);
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    init(1, 0);
    centroid_decomposition(1, 0, (int)(size[1] / 2));

    return 0;
}

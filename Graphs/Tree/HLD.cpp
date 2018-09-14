/*
    Name: Heavy-light decomposition of a tree
    
    Time complexity:
        -O(N) for initialization
        -O(logN) for LCA
    Space complexity: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> g[N], chains[N];
int size[N], depth[N], in_chain[N], parent[N];
int cnt_chains;

int dfs(int v, int prev) {
    parent[v] = prev;

    for (auto xt : g[v])
        if (xt != prev) {
            depth[xt] = depth[v] + 1;
            size[v] += dfs(xt, v);
        }

    return ++size[v];
}

void hld(int v, int prev, int chain) {
    chains[chain].push_back(v);
    in_chain[v] = chain;

    for (auto xt : g[v]) {
        if (xt != prev) {
            if (2 * size[xt] >= size[v])
                hld(xt, v, chain);
            else
                hld(xt, v, ++cnt_chains);
        }
    }
}

int find_lca(int u, int v) {
    while (in_chain[u] != in_chain[v]) {
        if (depth[u] > depth[v])
            u = parent[chains[in_chain[u]][0]];
        else
            v = parent[chains[in_chain[v]][0]];
    }

    return depth[u] > depth[v] ? v : u;
}

int main() {
    int n;
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, -1);
    hld(1, -1, ++cnt_chains);

    return 0;
}
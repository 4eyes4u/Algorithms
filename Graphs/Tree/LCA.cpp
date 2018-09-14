/*
    Name: Binary lifting for LCA

    Time complexity: 
        -O(N * logN) for initialization
        -O(logN) for LCA

* * *
    It's important to keep root parent of itself.
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int logN = 20;

vector<int> g[N];
int timer, in[N], out[N], st[N][logN];

void dfs(int v, int prev) {
    st[v][0] = prev;
    in[v] = ++timer;

    for (auto xt : g[v])
        if (xt != prev)
            dfs(xt, v);

    out[v] = ++timer;
}

bool in_tree(int u, int v) {
    return in[u] > in[v] && out[u] < out[v];
}

int find_lca(int u, int v) {
    if (u == v)
        return u;
    if (in_tree(u, v))
        return v;
    if (in_tree(v, u))
        return u;

    for (int deg = logN - 1; deg >= 0; deg--)
        if (!in_tree(v, st[u][deg]))
            u = st[u][deg];

    return st[u][0];
}

void init(int n) {
    for (int deg = 1; deg < logN; deg++)
        for (int i = 1; i <= n; i++)
            st[i][deg] = st[st[i][deg - 1]][deg - 1];
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1, u, v; i < n;i++) {
        scanf("%d%d", &u, &v);
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    dfs(1, 1);
    init(n);

    return 0;
}

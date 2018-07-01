/*
    Algorithm: Sparse table & binary lifting
    Complexity: O(V * logV) [where V is number of nodes in tree]
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int LogN = 20;

vector<int> g[N];
int timer, in[N], out[N], st[N][LogN];

void dfs(int v, int prev) {
    in[v] = ++timer;
    st[v][0] = prev;

    for (auto xt: g[v]) {
        if (xt == prev) continue;
        dfs(xt, v);
    }

    out[v] = ++timer;
}

bool in_tree(int a, int b) {
    return in[a] > in[b] && out[a] < out[b];
}

int find_lca(int a, int b) {
    if (a == b) return a;
    if (in_tree(a, b)) return b;
    if (in_tree(b, a)) return a;

    for (int i = LogN - 1; i >= 0; i--)
        if (!in_tree(b, st[a][i]))
            a = st[a][i];

    return st[a][0];
}

void init(int n) {
    for (int d = 1; d < LogN; d++)
        for (int i = 1; i <= n; i++)
            st[i][d] = st[st[i][d - 1]][d - 1];
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1, a, b; i < n;i++) {
        scanf("%d%d", &a, &b);
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    dfs(1, 1);
    init(n);

    return 0;
}

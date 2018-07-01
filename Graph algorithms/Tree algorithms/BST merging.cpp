/*
    Algorithm: BST merging
    Complexity: O(V * log^2 V) [where V is number of nodes in the tree]

* * *
Calculating number of distinct elements in a subtree of every node.
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

struct Node {
    int val;
    vector<int> adj;
} g[N];

int sol[N], aux[N], p[N]; // aux maintains solution for every subtree
set<int> skup[N];

int unite(int a, int b) {
    if (skup[a].size() < skup[b].size()) swap (a, b);

    for (auto xt: skup[b]) skup[a].insert(xt);
    aux[a] = skup[a].size();

    return a;
}

void dfs(int v, int prev) {
    p[v] = v;
    aux[v] = 1;
    skup[v].insert(g[v].val);

    for (auto xt: g[v].adj) {
        if (xt==prev) continue;

        dfs(xt, v);
        p[v] = unite(p[v], p[xt]);
    }

    sol[v] = aux[p[v]];
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", &g[i].val);

    for (int i = 1, a, b; i < n; i++) {
        scanf("%d%d", &a, &b);

        g[a].adj.emplace_back(b);
        g[b].adj.emplace_back(a);
    }

    dfs(1, 0);

    for (int i = 1; i <= n; i++)
        printf("%d ", sol[i]);

    return 0;
}

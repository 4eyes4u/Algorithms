/*
Algorithm: BST merging
Complexity: O(n*log^2n) [where n is number of nodes in the tree]

* * *
Number of distinct elements in a subtree of every node.
*/

#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;

struct Node
{
    int val;
    vector<int> adj;
} g[N];

int n, sol[N], aux[N];
set<int> skup[N];
int p[N];

int unite (int a, int b)
{
    if (skup[a].size()<skup[b].size()) swap (a, b);
    for (auto xt: skup[b]) skup[a].insert(xt);
    aux[a]=skup[a].size();

    return a;
}

void dfs (int v, int prev)
{
    p[v]=v;
    aux[v]=1;
    skup[v].insert(g[v].val);

    for (auto xt: g[v].adj)
    {
        if (xt==prev) continue;
        dfs (xt, v);
        p[v]=unite (p[v], p[xt]);
    }

    sol[v]=aux[p[v]];
}

int main()
{
    scanf ("%d", &n);
    for (int i=1;i<=n;i++) scanf ("%d", &g[i].val);
    for (int i=1;i<n;i++)
    {
        int a, b;
        scanf ("%d%d", &a, &b);
        g[a].adj.push_back(b);
        g[b].adj.push_back(a);
    }

    dfs (1, 0);

    for (int i=1;i<=n;i++) printf ("%d ", sol[i]);

    return 0;
}

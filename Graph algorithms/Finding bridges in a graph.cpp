/*
    Algorithm: Tarjan's algorithm for finding bridges in a graph
    Complexity: O(n+m) [where n is number of nodes and m number of edges in the graph]

* * *
Graph MUST NOT be a multigraph.
Graph is supposed to be undirected.
*/

#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;

vector<int> g[N];
int n, m;
int low[N], in[N], timer;

void Tarjan(int v, int prev)
{
    in[v]=low[v]=++timer;
    for (auto xt: g[v])
    {
        if (xt==prev) continue;
        if (!in[xt])
        {
            Tarjan(xt, v);
            if (low[xt]>in[v]) printf ("%d %d\n", v, xt);
            low[v]=min(low[v], low[xt]);
        }
        else low[v]=min(low[v], in[xt]);
    }
}

int main()
{
    scanf ("%d%d", &n, &m);
    for (int i=0;i<m;i++)
    {
        int a, b;
        scanf ("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    Tarjan(1, 0);

    return 0;
}

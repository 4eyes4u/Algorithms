/*
    Algorithm: Kosaraju's algorithm
    Complexity: O(V + E) [where E is number of edges and V number of nodes in the graph]
*/

#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;

vector<int> g[N], inv[N], scc[N];
stack<int> box;
int n, m;
int in[N], k;
bool mark[N];

void dfs1 (int v)
{
    mark[v]=1;
    for (auto xt: g[v]) if (!mark[xt]) dfs1 (xt);
    box.push(v);
}

void dfs2 (int v)
{
    in[v]=k;
    scc[k].push_back(v);
    for (auto xt: inv[v]) if (!in[xt]) dfs2(xt);
}

void Kosaraju()
{
    for (int i=1;i<=n;i++) if (!mark[i]) dfs1 (i);

    while (!box.empty())
    {
        int v=box.top();
        box.pop();
        if (in[v]) continue;

        k++;
        dfs2 (v);
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
        inv[b].push_back(a);
    }

    Kosaraju();

    return 0;
}

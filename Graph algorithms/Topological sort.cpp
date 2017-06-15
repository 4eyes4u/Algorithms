/*
    Algorithm: Topological sort
    Complexity: O(n) [where n is number of nodes in the graph]
*/

#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;

vector<int> g[N];
int n, m;
int topo[N], indeg[N];

bool Kahn ()
{
    int topoIdx=0;
    queue<int> q;
    for (int i=1;i<=n;i++) if (!indeg[i]) q.push(i);

    while (!q.empty())
    {
        int v=q.front();
        q.pop();
        topo[++topoIdx]=v;

        for (auto xt: g[v]) if (!--indeg[xt]) q.push(xt);
    }

    return (topoIdx==n);
}

int main()
{
    scanf ("%d%d", &n, &m);
    for (int i=0;i<m;i++)
    {
        int a, b;
        scanf ("%d%d", &a, &b);
        g[a].push_back(b);
        indeg[b]++;
    }

    Kahn();

    return 0;
}

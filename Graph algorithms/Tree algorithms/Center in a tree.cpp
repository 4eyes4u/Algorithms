/*
Algorithm: Finding center in a tree
Complexity: O(n) [where n is number of nodes in the tree]

* * *
Additional check is needed because sub-star graph.
*/

#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;

vector<int> g[N];
int dist[N], n;
bool path[N];

pair<int, int> dfs (int v, int prev)
{
    dist[v]=dist[prev]+1;
    pair<int, int> ret={dist[v], v};

    for (auto xt: g[v])
    {
        if (xt==prev) continue;
        ret=max(ret, dfs(xt, v));
    }

    return ret;
}

void makePath (int v)
{
    path[v]=true;
    for (auto xt: g[v]) if (dist[xt]==dist[v]-1) makePath(xt);
}

int main()
{
    scanf ("%d", &n);
    for (int i=1;i<n;i++)
    {
        int a, b;
        scanf ("%d%d", &, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dist[0]=-1;
    pair<int, int> p=dfs(dfs (1, 0).second, 0);
    makePath(p.second);

    for (int i=1;i<=n;i++)
    {
        if (dist[i]==p.first/2 && path[i])
        {
            printf ("%d", i);
            break;
        }
    }

    return 0;
}

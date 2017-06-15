/*
Algorithm: Centroid decomposition of a tree
Complexity: O(n*logn) [where n is number of nodes in the tree]
*/

#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int n, root;
int parent[N], sz[N];
bool mark[N];
vector<int> g[N], cdt[N];

int init (int v, int prev)
{
    for (auto xt: g[v])
    {
        if (xt==prev) continue;
        sz[v]+=init(xt, v);
    }

    return ++sz[v];
}

int dfs (int v, int prev, int bound)
{
    pair<int, int> child={0, 0};

    for (auto xt: g[v])
    {
        if (xt==prev || mark[xt]) continue;
        child=max(child, {sz[xt], xt});
    }

    if (child.first<=bound) return v;

    sz[v]-=child.first;
    sz[child.second]+=sz[v];
    return dfs (child.second, v, bound);
}

void centroidDecomposition (int v, int prev, int bound)
{
    int centroid=dfs (v, prev, bound);
    if (prev!=0) cdt[prev].push_back(centroid);
    if (prev!=0) parent[centroid]=prev;
    if (prev==0) root=centroid;
    mark[centroid]=true;

    for (auto xt: g[centroid])
    {
        if (mark[xt]) continue;
        centroidDecomposition(xt, centroid, (int)(sz[xt]/2));
    }
}

int main()
{
    scanf ("%d", &n);
    for (int i=1;i<n;i++)
    {
        int a, b;
        scanf ("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    init(1, 0);
    centroidDecomposition(1, 0, (int)(sz[1]/2));

    return 0;
}

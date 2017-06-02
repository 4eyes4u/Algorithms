/*
Algorithm: Sparse table & binary lifting
Complexity: O(n*logn) [where n is number of nodes in three]
*/

#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
const int LogN=20;

vector<int> g[N];
int n, st[N][LogN];
int timer, in[N], out[N];

void dfs (int v, int prev)
{
    in[v]=++timer;
    st[v][0]=prev;
    for (auto xt: g[v])
    {
        if (xt==prev) continue;
        dfs (xt, v);
    }

    out[v]=++timer;
}

bool inTree (int a, int b)
{
    return (in[a]>in[b] && out[a]<out[b]);
}

int findLCA (int a, int b)
{
    if (a==b) return a;
    if (inTree(a, b)) return b;
    if (inTree(b, a)) return a;
    for (int i=18;i>=0;i--) if (!inTree(b, st[a][i])) a=st[a][i];
    return st[a][0];
}

void init ()
{
    for (int d=1;d<=18;d++) for (int i=1;i<=n;i++) st[i][d]=st[st[i][d-1]][d-1];
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

    dfs(1, 1);
    init();

    return 0;
}

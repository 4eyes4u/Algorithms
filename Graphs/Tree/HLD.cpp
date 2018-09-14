/*
Algorithm: Heavy-light decomposition
Initial complexity: O(n)
Additional data structure complexity: O(n + Init) + q*O(Query)

[where n is number of nodes in the three and q number of queries]

* * *
Segment tree is built on every chain.
*/

#include <bits/stdc++.h>
#define mid (left+right)/2
using namespace std;

const int N=1e5+10;

vector<int> g[N], chain[N];
int in[N], idx[N], sz[N];
int n, cntChain;
int st[4*N], val[N];
int depth[N], parent[N];

void init (int idx, int left, int right, int *a)
{
    if (left==right)
    {
        st[idx]=a[left];
        return;
    }

    init (2*idx, left, mid, a);
    init (2*idx+1, mid+1, right, a);
    st[idx]=max(st[2*idx], st[2*idx+1]);
}

void update (int idx, int left, int right, int x, int val)
{
    if (left==right)
    {
        st[idx]=val;
        return;
    }

    if (x<=mid) update (2*idx, left, mid, x, val);
    else update (2*idx+1, mid+1, right, x, val);
    st[idx]=max(st[2*idx], st[2*idx+1]);
}

int query (int idx, int left, int right, int l, int r)
{
    if (l<=left && right<=r) return st[idx];

    int ret=0;
    if (l<=mid) ret=max(ret, query(2*idx, left, mid, l, r));
    if (r>mid) ret=max(ret, query(2*idx+1, mid+1, right, l, r));
    return ret;
}

int dfs (int v, int prev)
{
    for (auto xt: g[v])
    {
        if (xt==prev) continue;
        depth[xt]=depth[v]+1;
        parent[xt]=v;
        sz[v]+=dfs(xt, v);
    }

    return ++sz[v];
}

void HLD (int v, int prev, int curChain)
{
    in[v]=curChain;
    chain[curChain].push_back(v);
    for (auto xt: g[v])
    {
        if (xt==prev) continue;
        if (2*sz[xt]>sz[v]) HLD (xt, v, curChain);
        else HLD (xt, v, ++cntChain);
    }
}

int findLCA (int a, int b)
{
    while (in[a]!=in[b])
    {
        if (depth[chain[in[a]][0]]<depth[chain[in[b]][0]]) b=parent[chain[in[b]][0]];
        else a=parent[chain[in[a]][0]];
    }

    return ((depth[a]<depth[b])?a:b);
}

void enumerate ()
{
    int k=0;
    for (int i=1;i<=cntChain;i++) for (auto xt: chain[i]) idx[xt]=++k;
}

int main()
{
    scanf ("%d", &n);
    for (int i=1;i<=n;i++) scanf ("%d", &val[i]);
    for (int i=1;i<n;i++)
    {
        int a, b;
        scanf ("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs (1, 0);
    HLD (1, 0, ++cntChain);
    enumerate();
    init(1, 1, n, val);

    return 0;
}

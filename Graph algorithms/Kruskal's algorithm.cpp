/*
Algorithm: Kruskal's algorithm
Complexity: O(m*logn) [where n is number of nodes and m number of edges in the graph]
*/

#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
const int M=1e6+10;

struct Edge
{
    int a, b, w;
    Edge(): a(), b(), w() {}
    Edge(int _a, int _b, int _w): a(_a), b(_b), w(_w) {}
    bool operator<(const Edge &e) const
    {
        return w<e.w;
    }
} edges[M];

int n, m, dsu[N];

void init ()
{
    for (int i=1;i<=n;i++) dsu[i]=i;
}

int f (int x)
{
    if (dsu[x]==x) return x;
    return dsu[x]=f(dsu[x]);
}

void unite (int x, int y)
{
    dsu[f(x)]=f(y);
}

long long Kruskal ()
{
    long long mst=0;
    sort (edges, edges+m);

    for (int i=0;i<m;i++)
    {
        int a=edges[i].a;
        int b=edges[i].b;
        int w=edges[i].w;

        if (f(a)==f(b)) continue;
        mst+=1ll*w;
        unite (a, b);
    }

    return mst;
}

int main()
{
    scanf ("%d%d", &n, &m);
    init();
    for (int i=0;i<m;i++)
    {
        int a, b, w;
        scanf ("%d%d%d", &a, &b, &w);
        edges[i]=(Edge){a, b, w};
    }

    return 0;
}

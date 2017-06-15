/*
    Algorithm: Prim's algorithm
    Complexity: O(m*logn) [where n is number of nodes and m number of edges in the graph]
*/

#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;

vector<pair<int, int> > g[N];
int n, m;
bool added[N];

long long Prim (int source)
{
    long long mst=0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    for (auto pxt: g[source]) pq.push(pxt);

    while (!pq.empty())
    {
        int v=pq.top().first;
        int w=pq.top().second;
        if (added[v]) continue;
        added[v]=1;
        mst+=1ll*w;

        for (auto pxt: g[v]) if (!added[pxt.second]) pq.push(pxt);
    }

    return mst;
}

int main()
{
    scanf ("%d%d", &n, &m);
    for (int i=0;i<m;i++)
    {
        int a, b, w;
        scanf ("%d%d%d", &a, &b, &w);
        g[a].push_back({w, b});
        g[b].push_back({w, a});
    }

    printf ("%lld", Prim(1));

    return 0;
}

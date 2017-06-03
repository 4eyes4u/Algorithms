/*
Algorithm: Dijkstra's algorithm
Complexity O((m+n)*logn) [where n is number of nodes and m number of edges in the graph]
*/

#include <bits/stdc++.h>
using namespace std;

struct Entry
{
    int node;
    long long dist;
    bool operator<(const Entry &e) const
    {
        return dist>e.dist;
    }
};

const int N=1e5+10;
const long long inf=2e18;

vector<pair<int, int> > g[N];
int n, m;
long long dist[N];
bool mark[N];

void Dijkstra (int source)
{
    priority_queue<Entry> pq;
    for (int i=1;i<=n;i++) dist[i]=inf;
    dist[source]=0;
    pq.push({source, 0});

    while (!pq.empty())
    {
        int v=pq.top().node;
        long long d=pq.top().dist;
        if (mark[v]) continue;
        mark[v]=1;

        for (auto pxt: g[v])
        {
            int xt=pxt.first;
            long long w=1ll*pxt.second;
            if (mark[xt]) continue;

            if (d+w<dist[xt])
            {
                dist[xt]=d+w;
                pq.push({xt, dist[xt]});
            }
        }
    }
}

int main()
{
    scanf ("%d%d", &n, &m);
    for (int i=0;i<m;i++)
    {
        int a, b, w;
        scanf ("%d%d%d", &a, &b, &w);
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }

    Dijkstra (1);

    return 0;
}

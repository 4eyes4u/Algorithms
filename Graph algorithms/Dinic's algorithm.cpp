/*
Algorithm: Dinic's algorithm
Complexity: O(m*n^2) [where n is number of nodes and m number of edges in the graph]
*/

#include <bits/stdc++.h>
using namespace std;

const int N=210;
const int M=4e5+10;;
const int inf=1e9;

struct Edge
{
    int u, v, cap, flow, next;
} edges[M];

int n, m, E;
int head[N], dist[N];
int src, snk;
bool mark[N];

void add_edge (int u, int v, int c1, int c2)
{
    edges[E++]=(Edge){u, v, c1, 0, head[u]};
    head[u]=E-1;
    edges[E++]=(Edge){v, u, c2, 0, head[v]};
    head[v]=E-1;
}

bool bfs ()
{
    fill (dist+1, dist+n+1, -1);
    queue<int> q;
    dist[src]=0;

    for (q.push(src);!q.empty();q.pop())
    {
        int u=q.front();
        for (int e=head[u];e!=-1;e=edges[e].next)
        {
            int v=edges[e].v;
            if (edges[e].cap>edges[e].flow && dist[v]==-1)
            {
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
    }

    return (dist[snk]!=-1);
}

int dfs (int u, int minCap)
{
    if (minCap==0) return 0;
    if (u==snk) return minCap;

    for (int e=head[u];e!=-1;e=edges[e].next)
    {
        int v=edges[e].v;
        if (dist[v]!=dist[u]+1) continue;
        int augment=dfs (v, min(minCap, edges[e].cap-edges[e].flow));
        if (augment)
        {
            edges[e].flow+=augment;
            edges[e^1].flow-=augment;
            return augment;
        }
    }

    return 0;
}

int Dinic()
{
    int flow=0, blockingFlow=0;

    while (bfs())
    {
        do
        {
            blockingFlow=dfs(src, inf);
            flow+=blockingFlow;
        }
        while (blockingFlow);
    }

    return flow;
}

int main()
{
    scanf ("%d%d%d%d", &src, &snk, &n, &m);
    fill (head+1, head+n+1, -1);
    for (int i=0;i<m;i++)
    {
        int a, b, c;
        scanf ("%d%d%d", &a, &b, &c);
        add_edge(a, b, c, 0);
    }

    return 0;
}

/*
  Algorithm: Ford-Fulkerson algorithm
  Complexity: O(E*U) [where U is maximum flow]
*/

#include <bits/stdc++.h>
using namespace std;

const int N=1e2+10;
const int M=1e4+10;
const int inf=1e9;

struct Edge
{
  int u, v, c, f, next;
  Edge(): u(), v(), c(), f(), next() {};
  Edge(int _u, int _v, int _c, int _f, int _next): u(_u), v(_v), c(_c), f(_f), next(_next) {}
} edges[M];

int head[N], cntEdges;
bool mark[N];

void add_edge (int u, int v, int c1, int c2)
{
  edges[cntEdges++]=*new Edge(u, v, c1, 0, head[u]);
  head[u]=cntEdges-1;
  edges[cntEdges++]=*new Edge(v, u, c2, 0, head[v]);
  head[v]=cntEdges-1;
}

int dfs (int v, int flow, int t)
{
  mark[v]=1;
  if (v==t) return flow;

  for (int e=head[v];e!=-1;e=edges[e].next)
  {
    int xt=edges[e].v;
    if (edges[e].c-edges[e].f==0 || mark[xt]) continue;
    int augment=dfs(xt, min(flow, edges[e].c-edges[e].f), t);
    if (augment)
    {
      edges[e].f+=augment;
      edges[e^1].f-=augment;
      return augment;
    }
  }

  return 0;
}

int FordFulkerson (int s, int t)
{
  int maxFlow=0, flow=0;

  do
  {
    memset(mark, 0, sizeof mark);
    flow=dfs(s, inf, t);
    maxFlow+=flow;
  } while (flow);

  return maxFlow;
}

int main()
{
  int n, m, s, t;
  scanf ("%d%d%d%d", &n, &m, &s, &t);
  for (int i=1;i<=n;i++) head[i]=-1;

  for (int i=0;i<m;i++)
  {
    int u, v, c;
    scanf ("%d%d%d", &u, &v, &c);
    add_edge(u, v, c, 0);
  }

  printf ("%d\n", FordFulkerson(s, t));

  return 0;
}

/*
  Algorithm: Dinic's algorithm with scaling
  Complexity: O(E*V*log(MEC)) [where V is number of nodes, E is number of edges and MEC is maximum-edge capacity]
*/

#include <bits/stdc++.h>
using namespace std;

namespace ScalingDinic {
  const int N=1e2+10;
  const int M=1e4+10;
  const int inf=1e9;

  int dist[N], head[N];
  int V, E;

  struct Edge {
    int u, v, c, f, next;
    Edge(): u(), v(), c(), f(), next() {}
    Edge(int _u, int _v, int _c, int _f, int _next): u(_u), v(_v), c(_c), f(_f), next(_next) {}
  } edges[M];

  void init (int n) {
    V=n;
    E=0;
    fill(head+1, head+V+1, -1);
  }

  void add_edge (int u, int v, int c1, int c2) {
    edges[E++]=*new Edge(u, v, c1, 0, head[u]);
    head[u]=E-1;
    edges[E++]=*new Edge(v, u, c2, 0, head[v]);
    head[v]=E-1;
  }

  bool bfs (int s, int t, int bound) {
    fill(dist+1, dist+V+1, -1);
    dist[s]=0;
    queue<int> q;

    for (q.push(s);q.size();q.pop()) {
      int v=q.front();

      for (int e=head[v];e!=-1;e=edges[e].next) {
        int xt=edges[e].v;

        if (dist[xt]==-1 && edges[e].c-edges[e].f>=bound) {
          dist[xt]=dist[v]+1;
          q.push(xt);
        }
      }
    }

    return dist[t]!=-1;
  }

  bool dfs (int v, int t, int bound) {
    if (v==t) return 1;

    for (int e=head[v];e!=-1;e=edges[e].next) {
      int xt=edges[e].v;

      if (dist[xt]==dist[v]+1 && edges[e].c-edges[e].f>=bound) {
        bool flag=dfs(xt, t, bound);
        if (flag) {
          edges[e].f+=bound;
          edges[e^1].f-=bound;
          return 1;
        }
      }
    }

    return 0;
  }

  long long MaximumFlow (int s, int t) {
    long long maxFlow=0;

    for (int bound=(1<<30);bound>=1;bound>>=1) {
      if (!bfs(s, t, bound)) continue;
      while (dfs(s, t, bound)) maxFlow+=1ll*bound;
    }

    return maxFlow;
  }
}

int main() {
  int n, m, s, t;
  scanf ("%d%d%d%d", &n, &m, &s, &t);
  ScalingDinic::init(n);
  for (int i=0;i<m;i++)
  {
      int u, v, c;
      scanf ("%d%d%d", &u, &v, &c);
      ScalingDinic::add_edge(u, v, c, 0);
  }

  printf ("%lld\n", ScalingDinic::MaximumFlow(s, t));

  return 0;
}

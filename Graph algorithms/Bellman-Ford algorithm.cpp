/*
  Algorithm: Bellman-Ford algorithm
  Complexity: O(E * V) [where E is number of edges and V is number of nodes in the graph]
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
const int M = 1e4 + 10;
const int inf = 1e9 + 10;

struct Edge {
  int a, b, w;
} edges[M];

int n, m, dist[N];

bool BellmanFord(int source) {
  fill(dist + 1, dist + n + 1, inf);
  dist[source] = 0;

  for (int i = 1; i < n; i++) {
    for (int e = 0; e < m; e++) {
      int a = edges[e].a, b = edges[e].b, w = edges[e].w;
      dist[b] = min(dist[b], dist[a] + w);
    }
  }

  for (int e = 0; e < m; e++) {
    int a = edges[e].a, b = edges[e].b, w = edges[e].w;
    if (dist[a] + w < dist[b]) return 0;
  }

  return 1;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) scanf("%d%d%d", &edges[i].a, &edges[i].b, &edges[i].w);

  printf("%d\n", BellmanFord(1));

  return 0;
}

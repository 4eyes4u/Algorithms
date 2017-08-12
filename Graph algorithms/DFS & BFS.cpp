/*
  Algorithms: DFS & BFS
  Complexity: O(E + V) [where E is number of edges and V number of nodes in the graph]
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> g[N];
int n, m;
bool mark[N];

void dfs(int v) {
  mark[v] = 1;
  for (auto xt: g[v]) if (!mark[xt]) dfs(xt);
}

void bfs(int source) {
  queue<int> q;

  for (q.push(source); q.size(); q.pop()) {
    int v = q.front();
    mark[v] = 1;
    for (auto xt: g[v]) {
      if (mark[xt]) continue;
      q.push(xt);
      mark[xt] = 1;
     }
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
  }

  bfs(1);
  fill(mark + 1, mark + n + 1, 0);
  dfs(1);

  return 0;
}

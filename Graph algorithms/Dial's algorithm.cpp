/*
  Algoritam: Dajlov algoritam
  Slozenost: O(m + c * n) [gde je c gornje ogranicenje tezine grana]

* * *
Koristi se kada su tezine grana jako mali brojevi.
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
const int C = 100;

vector<pair<int, int>> g[N];
list<int> l[C * N];
list<int>::iterator it[N];
int dist[N], n, m;

inline int next_bucket(int idx) {
  for (int i = idx; i <= C * n; i++) if (l[i].size()) return i;
  return -1;
}

void Dial(int source) {
  for (int i = 1; i <= n; i++) {
    if (i != source) {
      dist[i] = C * n + 1;
      l[C * n + 1].push_back(i);
      it[i] = --l[C * n + 1].end();
    }
  }
  dist[source] = 0;
  l[0].push_back(source);
  it[0] = l[0].begin();

  int bucket = 0;
  while (1) {
    bucket = next_bucket(bucket);
    if (bucket == -1) break;

    int v = *l[bucket].begin();
    l[bucket].erase(l[bucket].begin());
    for (auto pxt: g[v]) {
      int xt = pxt.first, w = pxt.second;

      if (dist[v] + w < dist[xt]) {
        l[dist[xt]].erase(it[xt]);
        dist[xt] = dist[v] + w;
        l[dist[xt]].push_back(xt);
        it[xt] = --l[dist[xt]].end();
      }
    }
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    g[a].push_back({b, c});
    g[b].push_back({a, c});
  }

  Dial(1);
  for (int i = 1; i <= n; i++) printf("%d\n", dist[i]);

  return 0;
}

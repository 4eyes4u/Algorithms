/*
  Algoritam: Shortest Path Faster Algorithm (SPFA)
  Slozenost: O(k * m) [k je konstanta koja zavisi od grafa i nikad nije veca od V]

* * *
Iako je u teoriji daleko sporiji od Dajkstrinog algoritma, u praksi se pokazuje kao jako efikasan.
Moguce je ustanoviti postojojanje negativnog ciklusa (neki cvor je u queueu bio bar n puta). Dakle, teorijski je efikasan bar kao Bellman-Fordov algoritam.
Podrzava negativne tezine grana.
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int inf = 1e9 + 10;

vector<pair<int, int>> g[N];
int n, m, dist[N];
bool in[N];

void SPFA(int source) {
  queue<int> q;
  fill(dist + 1, dist + n + 1, inf);

  for (q.push(source), dist[source] = 0, in[source] = 1; q.size(); q.pop()) {
    int v = q.front();
    in[v] = 0;

    for (auto pxt: g[v]) {
      int xt = pxt.first, w = pxt.second;

      if (dist[v] + w < dist[xt]) {
        dist[xt] = dist[v] + w;

        if (!in[xt]) {
          q.push(xt);
          in[xt] = 1;
        }
      }
    }
  }
}

int main() {
  for (int i = 0; i < m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    g[a].push_back({b, c});
  }

  SPFA(1);
  for (int i = 1; i <= n; i++) printf("%d\n", dist[i]);

  return 0;
}

/*
    Name: Shortest-Path-Faster-Algorithm (SPFA)
    
    Time complexity: O(N * M)
    Space complexity: O(N + M)

* * *
    Very efficient in practice.
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int INF = 1e9 + 10;

vector<pair<int, int>> g[N];
int dist[N];
bool in[N];

void SPFA(int n, int source = 1) {
    queue<int> q;
    fill(dist + 1, dist + n + 1, INF);

    for (q.emplace(source), dist[source] = 0, in[source] = 1; q.size(); q.pop()) {
        int v = q.front();
        in[v] = 0;

        for (auto pxt: g[v]) {
            int xt = pxt.first;
            int w = pxt.second;

            if (dist[v] + w < dist[xt]) {
                dist[xt] = dist[v] + w;

                if (!in[xt]) {
                    q.emplace(xt);
                    in[xt] = 1;
                }
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, u, v, w; i < m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        g[u].emplace_back(v, w);
    }

    SPFA(n);

    return 0;
}

/*
    Name: Bellman-Ford algorithm

    Time complexity: O(N * M)
    Space complexity: O(N + M)
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
const int INF = 1e9 + 10;

struct Edge {
    int u, v, w;
};

int dist[N];
vector<Edge> edges;

int BellmanFord(int n, int m, int source = 1) {
    fill(dist + 1, dist + n + 1, INF);
    dist[source] = 0;

    for (int i = 1; i < n; i++)
        for (auto edge : edges)
            dist[edge.v] = min(dist[edge.v], dist[edge.u] + edge.w);

    for (auto edge : edges)
        if (dist[edge.u] + edge.w < dist[edge.v])
            // negative cycle
            return -1;

    return 1;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    edges.resize(m);
    for (int i = 0; i < m; i++)
        scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);

    BellmanFord(n, m);

    return 0;
}

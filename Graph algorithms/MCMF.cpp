/*
    Algorithm: MCMF with Bellman-Ford
    Complexity: O(V ^ 6) in general
                O(V ^ 4) for bipartite graph [where V is number of nodes in the network]
*/

#include <bits/stdc++.h>
using namespace std;

namespace MCMF {
    const int N = 1e2 + 10;
    const int M = N * N;
    const int inf = 1e9;

    int V = 0, E = 0, source, sink;
    int dist[N], parent[N];

    struct Edge {
        int u, v, cap, flow, cost;
    } edges[M];

    void init(int _V, int _source, int _sink) {
        V = _V;
        source = _source;
        sink = _sink;
    }

    inline void add_edge(int u, int v, int cap, int cost) {
        edges[E++] = {u, v, cap, 0, cost};
        edges[E++] = {v, u, 0, 0, -cost};
    }

    inline int push_unit() { // Bellman-Ford
        fill(dist, dist + V, inf);
        dist[source] = 0;

        bool flag = 1;
        while (flag) {
            flag = 0;
            for (int i = 0; i < E; i++) {
                Edge e = edges[i];
                int u = e.u, v = e.v;

                if (e.cap == e.flow || dist[u] == inf || dist[v] <= dist[u] + e.cost)
                    continue;
                
                dist[v] = dist[u] + e.cost;
                parent[v] = i;
                flag = 1;
            }
        }

        int node = sink;
        if (dist[sink] == inf) return 0;
        while (node != source) {
            int idx = parent[node];
            edges[idx].flow++;
            edges[idx ^ 1].flow--;
            node = edges[idx].u;
        }

        return dist[sink];
    }

    int push_flow(int flow) {
        int min_cost= 0;
        while (flow--) min_cost += push_unit();

        return min_cost;
    }
}

int main() {
    return 0;
}
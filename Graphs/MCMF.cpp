/*
    Name: Minimum-cost-maximum-flow with Bellman-Ford

    Time complexity:
        -O(N ^ 6) worst case
        -O(N ^ 4) for bipartite graph
    Space complexity: O(N + M)
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 10;

struct Edge {
    /*
        opposite is index of edge that is opposite
        to the given one in the residual graph
    */
    int v, cap, flow, cost, opposite;
};

vector<Edge> g[N];
int n, m, src, snk;

void add_edge(int u, int v, int cap1, int cost, int cap2 = 0) {
    int opposite_u = g[v].size();
    int opposite_v = g[u].size();
    g[u].push_back({v, cap1, 0, cost, opposite_u});
    g[v].push_back({u, cap2, 0, -cost, opposite_v});
}

namespace MCMF {
    const int INF = 1e9;
    int dist[N], parent[N];

    int push_unit() {
        fill(dist, dist + n + 1, INF);
        dist[src] = 0;

        bool flag = 1;
        while (flag) {
            flag = 0;
            for (int u = 0; u <= n; u++) {
                if (dist[u] != INF) {
                    for (int i = 0; i < g[u].size(); i++) {
                        Edge edge = g[u][i];

                        if (edge.cap > edge.flow && dist[edge.v] <= dist[u]) {
                            dist[edge.v] = dist[u] + edge.cost;
                            parent[edge.v] = i;
                            flag = 1;
                        }
                    }
                }
            }
        }

        if (dist[snk] == INF)
            return 0;
        
        int u = snk;
        while (u != src) {
            int edge_idx = parent[u];
            g[u][edge_idx].flow++;
            g[g[u][edge_idx].v][g[u][edge_idx].opposite].flow--;
            u = g[u][edge_idx].v;
        }
        
        return dist[snk];
    }

    int push_flow(int flow) {
        for (int u = 0; u <= n; u++)
            for (auto &edge : g[u])
                edge.flow = 0;

        int min_cost = 0;
        while (flow--)
            min_cost += push_unit();
        
        return min_cost;
    }
}

namespace FordFulkerson {
    const int INF = 1e9;
    bool mark[N];

    int dfs(int u, int min_cap) {
        mark[u] = 1;
        if (u == snk || !min_cap)
            return min_cap;
        
        for (auto &edge : g[u]) {
            if (!mark[edge.v] && edge.cap > edge.flow) {
                int augment = dfs(edge.v, min(min_cap, edge.cap - edge.flow));

                if (augment) {
                    edge.flow += augment;
                    g[edge.v][edge.opposite].flow -= augment;
                    return augment;
                }
            }
        }

        return 0;
    }

    int max_flow() {
        int ret = 0, flow = 0;
        
        do {
            memset(mark, 0, sizeof(mark));
            flow = dfs(src, INF);
            ret += flow;
        } while(flow);

        return ret;
    }
}

int main() {
    scanf("%d%d%d%d", &n, &m, &src, &snk);
    for (int i = 0, u, v, cap, cost; i < m; i++) {
        scanf("%d%d%d%d", &u, &v, &cap, &cost);
        add_edge(u, v, cap, cost);
    }

    int max_flow = FordFulkerson::max_flow();
    int min_cost = MCMF::push_flow(max_flow);
    printf("%d\n", min_cost);

    return 0;
}

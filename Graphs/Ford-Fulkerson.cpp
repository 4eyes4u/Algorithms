/*
    Name: Ford-Fulkerson algorithm

    Time complexity: O(max_flow * M)
    Space complexity: O(M)
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;

struct Edge {
    /*
        opposite is index of edge that is opposite
        to the given one in the residual graph
    */
    int v, cap, flow, opposite;
};

vector<Edge> g[N];
int src, snk, n, m;

void add_edge(int u, int v, int cap1, int cap2 = 0) {
    int opposite_u = g[v].size();
    int opposite_v = g[u].size();
    g[u].push_back({v, cap1, 0, opposite_u});
    g[v].push_back({u, cap2, 0, opposite_v});
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
    for (int i = 0, u, v, cap; i < m; i++) {
        scanf("%d%d%d", &u, &v, &cap);
        add_edge(u, v, cap);
    }

    int max_flow = FordFulkerson::max_flow();
    printf("%d\n", max_flow);

    return 0;
}
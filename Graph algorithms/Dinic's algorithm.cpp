/*
    Algorithm: Dinic's algorithm
    Complexity: O(E * V ^ 2) [where V is number of nodes and E number of edges in the graph]
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 210;
const int M = 4e5 + 10;;
const int inf = 1e9;

struct Edge {
    int u, v, cap, flow, next;

    Edge(int u = 0, int v = 0, int cap = 0, int flow = 0, int next = -1) {
        this -> u = u;
        this -> v = v;
        this -> cap = cap;
        this -> flow = flow;
        this -> next = next;
    }
} edges[M];

int head[N], dist[N], cnt_edges;
bool mark[N];

void add_edge(int u, int v, int cap1, int cap2) {
    // head[v] saves last edge with endpoint v
    // edge.next saves index of previous head[v]
    // we can iterate through neighbours by taking edge.next

    edges[cnt_edges++] = *new Edge(u, v, cap1, 0, head[u]);
    head[u] = cnt_edges - 1;

    edges[cnt_edges++] = *new Edge(v, u, cap2, 0, head[v]);
    head[v] = cnt_edges-1;
}

bool bfs(int n, int src, int snk) {
    fill(dist + 1, dist + n + 1, -1);
    queue<int> q;

    for (q.emplace(src), dist[src] = 0; q.size(); q.pop()) {
        int u = q.front();

        for (int e = head[u]; e != -1; e = edges[e].next) {
            int v = edges[e].v;

            if (edges[e].cap > edges[e].flow && dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.emplace(v);
            }
        }
    }

    return dist[snk] != -1;
}

int dfs(int u, int min_cap, int snk) {
    if (!min_cap) return 0;
    if (u == snk) return min_cap;

    for (int e = head[u]; e != -1; e = edges[e].next) {
        int v = edges[e].v;
        if (dist[v] != dist[u] + 1) continue;

        int augment = dfs(v, min(min_cap, edges[e].cap - edges[e].flow), snk);
        if (augment) {
            edges[e].flow += augment;
            edges[e ^ 1].flow -= augment;
            return augment;
        }
    }

    return 0;
}

int Dinic(int n, int src, int snk) {
    int max_flow = 0, blocking_flow = 0;

    while (bfs(n, src, snk)) {
        do
        {
            blocking_flow = dfs(src, inf, snk);
            max_flow += blocking_flow;
        }
        while (blocking_flow);
    }

    return max_flow;
}

int main() {
    int n, m, src, snk;
    scanf("%d%d%d%d", &n, &m, &src, &snk);

    fill(head + 1, head + n + 1, -1);

    for (int i = 0, a, b, c; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        add_edge(a, b, c, 0);
    }

    printf("%d\n", Dinic(n, src, snk));

    return 0;
}

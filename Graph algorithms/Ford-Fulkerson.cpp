/*
    Algorithm: Ford-Fulkerson algorithm
    Complexity: O(E * F) [where F is maximum flow]
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 10;
const int M = 1e4 + 10;
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

int head[N], cnt_edges;
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

int dfs(int v, int flow, int snk) {
    mark[v] = 1;
    if (v == snk) return flow;

    for (int e = head[v]; e != -1; e = edges[e].next) {
        int xt = edges[e].v;
        if (edges[e].cap - edges[e].flow == 0 || mark[xt]) continue;
        
        int augment = dfs(xt, min(flow, edges[e].cap - edges[e].flow), snk);
        if (augment) {
            edges[e].flow += augment;
            edges[e ^ 1].flow -= augment;
            return augment;
        }
    }

    return 0;
}

int FordFulkerson(int src, int snk) {
    int max_flow = 0, flow = 0;

    do {
        memset(mark, 0, sizeof mark);
        flow = dfs(src, inf, snk);
        max_flow += flow;
    } while(flow);

    return max_flow;
}

int main() {
    int n, m, src, snk;
    scanf("%d%d%d%d", &n, &m, &src, &snk);
    fill(head + 1, head + n + 1, -1);

    for (int i = 0, u, v, cap; i < m; i++) {
        scanf("%d%d%d", &u, &v, &cap);
        add_edge(u, v, cap, 0);
    }

    printf("%d\n", FordFulkerson(src, snk));

    return 0;
}

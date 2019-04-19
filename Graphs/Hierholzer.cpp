/*
    Name: Hierholzer's algorithm

    Time complexity: O(M)
    Space complexity: O(N + M)
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

struct Edge {
    int adj;
    list<Edge>::iterator inv;

    Edge(int _adj) : adj(_adj) {}
};

list<Edge> g[N];
vector<int> path;

void Hierholzer(int v) {
    while (g[v].size() > 0) {
        int adj = g[v].front().adj;
        g[adj].erase(g[v].front().inv);
        g[v].pop_front();
        Hierholzer(adj);
    }
    path.emplace_back(v);
}

void add_edge(int u, int v) {
    g[u].emplace_front(v);
    g[v].emplace_front(u);
    g[u].begin()->inv = g[v].begin();
    g[v].begin()->inv = g[u].begin();
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, u, v; i < m; i++) {
        scanf("%d%d", &u, &v);
        add_edge(u, v);
    }

    Hierholzer(1);
    for (const int &v : path)
        printf("%d ", v);

    return 0;
}
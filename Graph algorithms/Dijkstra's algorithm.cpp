/*
    Algorithm: Dijkstra's algorithm
    Complexity O((E + V) * logV) [where V is number of nodes and E number of edges in the graph]
*/

#include <bits/stdc++.h>
using namespace std;

struct Entry {
    int node;
    long long dist;

    Entry(int node = 0, long long dist = 0) {
        this -> node = node;
        this -> dist = dist;
    }
    
    bool operator < (const Entry &other) const {
    	return dist > other.dist;
    }
};

const int N = 1e5 + 10;
const long long inf = 2e18;

vector<pair<int, int>> g[N];
long long dist[N];

void Dijkstra(int source, int n) {
    priority_queue<Entry> pq;

    for (int i = 1; i <= n; i++) dist[i] = inf;
    pq.emplace(source, dist[source] = 0);
    
    bool mark[N];
    memset(mark, 0, sizeof(mark));
    
    while (!pq.empty()) {
        int v = pq.top().node;
        long long d = pq.top().dist;
        pq.pop();
        
        if (mark[v]) continue;
        mark[v] = 1;

        for (auto pxt: g[v]) {
            int xt = pxt.first;
            long long w = 1ll * pxt.second;
            if (mark[xt]) continue;

            if (d + w < dist[xt])
                pq.emplace(xt, dist[xt] = d + w);
        }
    }
}

int main() {
	int n, m;
    scanf("%d%d", &n, &m);
    
    for (int i = 0; i < m; i++) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        g[a].emplace_back(b, w);
        g[b].emplace_back(a, w);
    }

    Dijkstra(1, n);

    return 0;
}

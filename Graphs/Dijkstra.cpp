/*
    Name: Dijkstra's algorithm

    Time complexity: O((N + M) * logN)
    Spce complexity: O(N + M)
*/

#include <bits/stdc++.h>
using namespace std;

struct Entry {
    int node;
    long long dist;

    Entry(int node = 0, long long dist = 0) {
        this->node = node;
        this->dist = dist;
    }
    
    bool operator < (const Entry &other) const {
    	return dist > other.dist;
    }
};

const int N = 1e5 + 10;
const long long INF = 2e18;

vector<pair<int, int>> g[N];
long long dist[N];
bool mark[N];

void Dijkstra(int n, int source = 1) {
    fill(dist + 1, dist + n + 1, INF);
    priority_queue<Entry> pq;
    pq.emplace(source, dist[source] = 0);
    
    while (!pq.empty()) {
        int v = pq.top().node;
        long long d = pq.top().dist;
        pq.pop();
        
        if (!mark[v]) {
            mark[v] = 1;

            for (auto pxt : g[v]) {
                int xt = pxt.first;
                long long w = 1ll * pxt.second;
                
                if (!mark[xt])
                    if (d + w < dist[xt])
                        pq.emplace(xt, dist[xt] = d + w);
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
        g[v].emplace_back(u, w);
    }

    Dijkstra(n);

    return 0;
}

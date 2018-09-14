/*
    Algorithm: Prim's algorithm
    Complexity: O(m*logn) [where n is number of nodes and m number of edges in the graph]
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

vector<pair<int, int>> g[N];
bool added[N];

long long Prim (int source = 1) {
    long long mst = 0;
    priority_queue<pair<int, int>,
                    vector<pair<int, int>>,
                    greater<pair<int, int>>> pq;
    
    for (auto pxt : g[source])
        pq.emplace(pxt);

    while (!pq.empty()) {
        int w = pq.top().first;
        int v = pq.top().second;
        
        if (!added[v]) {
            added[v] = 1;
            mst += 1ll * w;

            for (auto pxt : g[v])
                if (!added[pxt.second])
                    pq.emplace(pxt);
        }
    }

    return mst;
}

int main() {
    int n, m;
    scanf ("%d%d", &n, &m);
    for (int i = 0, u, v, w; i < m; i++) {
        scanf ("%d%d%d", &u, &v, &w);
        g[u].push_back({w, v});
        g[v].push_back({w, u});
    }

    long long mst = Prim();

    return 0;
}

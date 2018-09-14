/*
    Name: Fiding bridges in a tree (Tarjan's algorithm)

    Time complexity: O(N + M)
    Space complexity: O(N + M)

* * *
    Graph MUST NOT be a multigraph.
    Graph is supposed to be undirected.
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> g[N];
vector<pair<int, int>> bridges;
int low[N], in[N], timer;

void Tarjan(int v, int prev) {
    in[v] = low[v] = ++timer;
    
    for (auto xt : g[v]) {
        if (xt != prev) {
            if (!in[xt]) {
                Tarjan(xt, v);
                
                if (low[xt] > in[v])
                    bridges.emplace_back(v, xt);

                low[v] = min(low[v], low[xt]);
            }
            else
                low[v] = min(low[v], in[xt]);
        }
    }
}

int main() {
	int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, u, v; i < m; i++) {
        scanf("%d%d", &u, &v);
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    Tarjan(1, -1);

    return 0;
}

/*
    Algorithm: Tarjan's algorithm for finding bridges in a graph
    Complexity: O(V + E) [where V is number of nodes and E number of edges in the graph]

* * *
Graph MUST NOT be a multigraph.
Graph is supposed to be undirected.
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> g[N];
int low[N], in[N], timer;

void Tarjan(int v, int prev) {
    in[v] = low[v] = ++timer;
    
    for (auto xt: g[v]) {
        if (xt == prev) continue;
        
        if (!in[xt]) {
            Tarjan(xt, v);
            
            if (low[xt] > in[v])
            	printf("%d %d\n", v, xt); // bridge is found

            low[v] = min(low[v], low[xt]);
        }
        else low[v] = min(low[v], in[xt]);
    }
}

int main() {
	int n, m;
    scanf("%d%d", &n, &m);
    
    for (int i = 0, a, b; i < m; i++) {
        scanf("%d%d", &a, &b);
        
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    Tarjan(1, 0);

    return 0;
}

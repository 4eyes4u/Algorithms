/*
    Name: Tarjan SCC algorithm

    Time complexity: O(N + M)
    Space complexity: O(N + M)
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

struct Node {
    vector<int> adj;
    int lowlink, index, in;
    bool onstack;
} g[N];

vector<int> scc[N], topo;
stack<int> box;
int index, n_scc;

void strong_connect(int v) {
    int w = 0;
    do {
        w = box.top();
        box.pop();
        g[w].onstack = false;
        scc[n_scc].emplace_back(w);
        g[w].in = n_scc;
    } while (v != w);
}

void dfs(int v) {
    index++;
    g[v].index = index;
    g[v].lowlink = index;
    box.push(v);
    g[v].onstack = true;

    for (const int &xt : g[v].adj) {
        if (!g[v].index) {
            dfs(xt);
            g[v].lowlink = min(g[v].lowlink, g[xt].lowlink);
        }
        else if (g[xt].onstack)
            g[v].lowlink = min(g[v].lowlink, g[xt].index);
    }

    if (g[v].index == g[v].lowlink) {
        n_scc++;
        topo.emplace_back(n_scc);
        strong_connect(v);
    }
}

void Tarjan(int n) {
    for (int i = 1; i <= n; i++)
        if (!g[i].index)
            dfs(i);
}

int main() {
    int n, m;
    scanf("%d", &m);
    for (int i = 0, u, v; i < m; i++) {
        scanf("%d%d", &u, &v);
        g[u].adj.emplace_back(v);
    }

    Tarjan(n);
    // toposort of the condensation graph as a byproduct
    reverse(topo.begin(), topo.end());

    return 0;
}
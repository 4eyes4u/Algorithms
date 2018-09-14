/*
    Algorithm: Topological sort
    Complexity: O(V) [where V is number of nodes in the graph]
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> g[N];
int topo[N], in_deg[N];

bool Kahn(int n) {
    int topo_idx = 0;
    queue<int> q;
    for (int i = 1; i <= n; i++) 
        if (!in_deg[i])
            q.push(i);

    while (q.size()) {
        int v = q.front();
        q.pop();
        topo[++topo_idx]=v;

        for (auto xt: g[v])
            if (!--in_deg[xt])
                q.emplace(xt);
    }

    return topo_idx == n;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0, a, b; i < m; i++) {
        scanf("%d%d", &a, &b);
        g[a].emplace_back(b);
        in_deg[b]++;
    }

    if (Kahn(n))
        for (int i = 0; i < n; i++)
            printf("%d ", topo[i]);

    return 0;
}

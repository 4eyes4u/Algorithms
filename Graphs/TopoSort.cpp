/*
    Name: Topological sort (Kahn's algorithm)

    Time complexity: O(N + M)
    Space complexity: O(N + M)
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
    for (int i = 0, u, v; i < m; i++) {
        scanf("%d%d", &u, &v);
        g[u].emplace_back(v);
        in_deg[v]++;
    }

    bool flag = Kahn(n);

    return 0;
}

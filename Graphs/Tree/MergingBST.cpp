/*
    Name: Merging binary search trees (smaller to bigger)

    Time complexity: O(N * log^2(N))
    Space complexity: O(N)

* * *
    Calculating number of disctinct elements in every subtree.
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> g[N];
int val[N], sol[N], tmp[N], p[N];
set<int> sets[N];

int unite(int a, int b) {
    if (sets[a].size() < sets[b].size())
        swap(a, b);
    
    for (auto x : sets[b])
        sets[a].insert(x);
    tmp[a] = sets[a].size();

    return a;
}

void dfs(int v, int prev) {
    p[v] = v;
    tmp[v] = 1;
    sets[v].insert(val[v]);

    for (auto xt : g[v]) {
        if (xt != prev) {
            dfs(xt, v);
            p[v] = unite(p[v], p[xt]);
        }
    }

    sol[v] = tmp[p[v]];
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", val + i);

    for (int i = 1, u, v; i < n; i++) {
        scanf("%d%d", &u, &v);
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    dfs(1, -1);

    for (int i = 1; i <= n; i++)
        printf("%d ", sol[i]);

    return 0;
}

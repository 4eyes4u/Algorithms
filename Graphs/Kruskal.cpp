/*
    Name: Kruskal's algorithm

    Time complexity: O(M * logN)
    Space complexity: O(N + M)
    
* * *
    DSU is implented with 'path compression' and without 'union by rank'.
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

struct Edge {
    int u, v, w;
};

vector<Edge> edges;
int dsu[N];

void init(int n) {
    for (int i = 1; i <= n; i++)
    	dsu[i] = i;
}

int find(int x) {
    if (dsu[x] == x) return x;
    return dsu[x] = find(dsu[x]);
}

void unite(int x, int y) {
    dsu[find(x)] = find(y);
}

long long Kruskal(int n, int m) {
    long long mst = 0;
    sort(edges.begin(), edges.end(),
        [](const Edge &a, const Edge &b) { return a.w < b.w; });


    for (auto edge : edges) {
        if (find(edge.u) != find(edge.v)) {
            mst += 1ll * edge.w;
            unite(edge.u, edge.v);
        }
    }

    return mst;
}

int main() {
	int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
        scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);
    
    init(n);
    long long mst = Kruskal(n, m);

    return 0;
}

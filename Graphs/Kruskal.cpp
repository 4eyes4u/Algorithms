/*
    Algorithm: Kruskal's algorithm
    Complexity: O(E * logV) [where V is number of nodes and E number of edges in the graph]
    
* * *
DSU is implented with path compression and without union by rank.
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int M = 1e6 + 10;

struct Edge {
    int a, b, w;
    
    Edge(int a = 0, int b = 0, int w = 0) {
    	this -> a = a;
    	this -> b = b;
    	this -> w = w;
    }
} edges[M];

int dsu[N];

void init(int n) {
    for (int i = 1; i <= n; i++)
    	dsu[i] = i;
}

int f(int x) {
    if (dsu[x] == x) return x;
    return dsu[x] = f(dsu[x]);
}

void unite(int x, int y) {
    dsu[f(x)] = f(y);
}

long long Kruskal(int n, int m) {
    long long mst = 0;
    sort(edges, edges + m, [](const Edge &a, const Edge &b) -> bool { return a.w < b.w; });

    for (int i = 0; i < m; i++) {
        int a = edges[i].a;
        int b = edges[i].b;
        int w = edges[i].w;

        if (f(a) != f(b)) {
		    mst += 1ll * w;
		    unite(a, b);
		}
    }

    return mst;
}

int main() {
	int n, m;
    scanf("%d%d", &n, &m);
    init(n);
    
    for (int i = 0; i < m; i++) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        edges[i] = (Edge){a, b, w};
    }
    
    printf("%lld\n", Kruskal(n, m));

    return 0;
}

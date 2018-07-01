/*
    Algorithm: Kosaraju's algorithm
    Complexity: O(V + E) [where E is number of edges and V number of nodes in the graph]
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> g[N], inv[N], scc[N];
stack<int> box;
int in[N];
bool mark[N];

void dfs1(int v) {
    mark[v] = 1;
    
    for (auto xt: g[v])
    	if (!mark[xt])
    		dfs1(xt);
    
    box.push(v);
}

void dfs2(int v, int k){
    in[v] = k;
    scc[k].push_back(v);
    
    for (auto xt: inv[v])
    	if (!in[xt])
    		dfs2(xt, k);
}

int Kosaraju(int n) { // returns number of SCC
	int ret = 0;

    for (int i = 1; i <= n; i++)
    	if (!mark[i])
    		dfs1(i);

    while (!box.empty()) {
        int v = box.top();
        box.pop();
        if (in[v]) continue;

        ret++;
        dfs2(v, ret);
    }
    
    return ret;
}

int main() {
	int n, m;
    scanf("%d%d", &n, &m);
    
    for (int i = 0, a, b; i < m; i++) {
        scanf("%d%d", &a, &b);
        
        g[a].push_back(b);
        inv[b].push_back(a);
    }

    printf("%d\n", Kosaraju(n));

    return 0;
}

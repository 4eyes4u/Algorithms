/*
    Name: Koasaraju's algorithm

    Time complexity: O(N + M)
    Space complexity: O(N + M)
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
    scc[k].emplace_back(v);
    in[v] = k;
    
    for (auto xt: inv[v])
    	if (!in[xt])
    		dfs2(xt, k);
}

int Kosaraju(int n) {
	int ret = 0;

    for (int i = 1; i <= n; i++)
    	if (!mark[i])
    		dfs1(i);

    while (!box.empty()) {
        int v = box.top();
        box.pop();
        
        if (!in[v]) {
            ret++;
            dfs2(v, ret);
        }
    }
    
    // number of SCC
    return ret;
}

int main() {
	int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, u, v; i < m; i++) {
        scanf("%d%d", &u, &v);
        g[u].emplace_back(v);
        inv[v].emplace_back(u);
    }

    int cnt_scc = Kosaraju(n);

    return 0;
}

/*
    Name: Hopcroft-Karp algorithm

    Time complexity: O(M * sqrt(N))
    Space complexity: O(N + M)

* * *
Test problem: https://www.spoj.com/problems/MATCHING/
*/

#include <vector>
#include <iostream>
#include <queue>

const int N = 1e5 + 10;
const int INF = 1e9;
// NONE is sentinel for unpaired nodes
const int NONE = 0;

std::vector<int> g[N];
int match[N], dist[N];

bool bfs(const int &nu) {
    std::queue<int> q;
    for (int i = 1; i <= nu; i++) {
        if (match[i] == NONE) {
            dist[i] = 0;
            q.emplace(i);
        }
        else dist[i] = INF;
    }

    dist[NONE] = INF;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        if (node != NONE) {
            for (const int &xt : g[node]) {
                // if match[xt] is not visited path is alternating
                if (dist[match[xt]] == INF) {
                    dist[match[xt]] = dist[node] + 1;
                    q.emplace(match[xt]);
                }
            }
        }
    }

    return dist[NONE] != INF;
}

bool dfs(int u) {
    if (u != NONE) {
        for (const int &v : g[u]) {
            if (dist[match[v]] == dist[u] + 1) {
                if (dfs(match[v])) {
                    match[u] = v;
                    match[v] = u;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    // full augmented path is obtained
    return true;
}

int HopcroftKarp(const int &nu) {
    int matching = 0;
    while (bfs(nu)) {
        for (int i = 1; i <= nu; i++)
            if (match[i] == NONE && dfs(i))
                matching++;
    }
    
    return matching;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int nu, nv, m;
    std::cin >> nu >> nv >> m;
    for (int i = 0, u, v; i < m; i++) {
        std::cin >> u >> v;
        g[u].emplace_back(v + nu);
        g[v + nu].emplace_back(u);
    }

    std::cout << HopcroftKarp(nu) << std::endl;

    return 0;
}
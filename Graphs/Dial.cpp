/*
    Name: Dial's algorithm

    Time complexity: O(M + N * C)
    Space complexity: O(N * C)

* * *
Can be used when C is small number.
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
const int C = 100;

vector<pair<int, int>> g[N];
list<int> l[C * N];
list<int>::iterator it[N];
int dist[N];

inline int next_bucket(int n, int idx) {
    for (int i = idx; i <= C * n; i++)
        if (l[i].size())
            return i;
    
    return -1;
}

void Dial(int n, int source = 1) {
    for (int i = 1; i <= n; i++) {
        if (i != source) {
            dist[i] = C * n + 1;
            l[C * n + 1].push_back(i);
            it[i] = --l[C * n + 1].end();
        }
    }
    
    dist[source] = 0;
    l[0].push_back(source);
    it[0] = l[0].begin();

    int bucket = 0;
    while (1) {
        bucket = next_bucket(n, bucket);
        if (bucket == -1)
            break;

        int v = *l[bucket].begin();
        l[bucket].erase(l[bucket].begin());
        
        for (auto pxt: g[v]) {
            int xt = pxt.first;
            int w = pxt.second;

            if (dist[v] + w < dist[xt]) {
                l[dist[xt]].erase(it[xt]);
                dist[xt] = dist[v] + w;
                l[dist[xt]].push_back(xt);
                it[xt] = --l[dist[xt]].end();
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0, u, v, w; i < m; i++) {
        scanf("%d%d%d", &u, &v, &w);

        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    Dial(n);

    return 0;
}

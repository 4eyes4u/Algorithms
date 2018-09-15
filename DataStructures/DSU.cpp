/*
    Name: Disjoint-set-union (DSU)
    
    Time complexity:
        -O(N) for initialization
        -O(logN) per operation

* * *
    Without 'union by rank' heuristic.
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int dsu[N];

void init(int n) {
    for (int i = 1; i <= n; i++)
        dsu[i] = i;
}

int find(int x) {
    if (dsu[x] == x)
        return x;
    return dsu[x] = find(dsu[x]);
}

void unite(int x, int y) {
    dsu[find(x)] = find(y);
}

int main() {
    int n;
    scanf("%d", &n);
    init(n);

    return 0;
}

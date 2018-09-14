/*
    Name: Transitive closure of a graph (Floyd-Warshall algorithm)

    Time complexity: O(N ^ 3)
    Space complexity: O(N ^ 2)
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 5e2 + 10;

int g[N][N], f[N][N];

void FloydWarshall(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            f[i][j] = g[i][j];

        f[i][i] = 0;
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                f[i][j] |= f[i][k] & f[k][j];
}

int main() {
	int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, u, v; i < m; i++) {
        scanf("%d%d", &u, &v);
        g[u][v] = 1;
    }

    FloydWarshall(n);
    
    return 0;
}

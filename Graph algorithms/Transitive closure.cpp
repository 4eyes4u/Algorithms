/*
    Algorithm: Floyd-Warshall algorithm for calculating transitive closure of digraph
    Complexity: O(n ^ 3) [where n is number of nodes]
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 500 + 10;

int g[N][N], f[N][N], n, m;

void FloydWarshall() {
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
    scanf("%d%d", &n, &m);
    for (int i = 0, a, b; i < m; i++) {
        scanf("%d%d", &a, &b);
        g[a][b] = 1;
    }

    FloydWarshall();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            printf("%d ", f[i][j]);

        puts("");
    }

    return 0;
}
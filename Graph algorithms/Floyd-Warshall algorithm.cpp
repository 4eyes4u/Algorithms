/*
Algorithm: Floyd-Warshall algorithm
Complexity: O(n^3) [where n is number of nodes in the graph]
*/

#include <bits/stdc++.h>
using namespace std;

const int inf=1e9;
const int N=510;

int g[N][N], dist[N][N];
int n, m;

void FloydWarshall ()
{
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++) dist[i][j]=g[i][j];
        dist[i][i]=0;
    }

    for (int k=1;k<=n;k++)
    {
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
}

int main()
{
    scanf ("%d%d", &n, &m);
    for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) g[i][j]=inf;
    for (int i=0;i<m;i++)
    {
        int a, b, c;
        scanf ("%d%d%d", &a, &b, &c);
        g[a][b]=c;
        g[b][a]=c;
    }

    FloydWarshall();

    return 0;
}

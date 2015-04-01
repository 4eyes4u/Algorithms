/*
    Opis: Najkraci put izmedju svih parova cvorova u grafu
    Slozenost: O(V^3)
*/

#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N=1e5+10;
const int INF=987654321;

int n, dist[N][N], floyd[N][N];

void FloydWarshall ()
{
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            floyd[i][j]=dist[i][j];
        }
        floyd[i][i]=0;
    }
    for (int k=1;k<=n;k++)
    {
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                if (floyd[i][k]+floyd[k][j]<floyd[i][j])
                {
                    floyd[i][j]=floyd[i][k]+floyd[k][j];
                }
            }
        }
    }
}

int main()
{
	n=3; //broj cvorova
	dist[1][1]=0; //sam do sebe
	dist[1][2]=3; //rastojanje od cvora 1 do cvora 2
	dist[1][3]=INF; //ne postoji put od cvora 1 do cvora 3;

	return 0;
}

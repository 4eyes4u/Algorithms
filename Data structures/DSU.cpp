/*
Data structure: DSU
Complexities:
    Make Set O(1)
    Find Parent O(logn)
    Unite O(logn)
*/

#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int dsu[N], n;

void init ()
{
    for (int i=1;i<=n;i++) dsu[i]=i;
}

int f (int x)
{
    if (dsu[x]==x) return x;
    return dsu[x]=f(dsu[x]);
}

void unite (int x, int y)
{
    x=f(x), y=f(y);
    dsu[x]=y;
}

int main()
{
    scanf ("%d", &n);
    init ();

    return 0;
}

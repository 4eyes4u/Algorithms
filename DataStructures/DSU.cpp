/*
Data structure: DSU
Time complexity:
    Init O(n) [where n is number of sets]
    Find Parent O(logn) [where n is number of sets]
    Unite O(logn) [where n is number of sets]
Memory complexity: O(n) [where n is number of sets]

* * *
Without 'union by rank' heuristic.
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
    dsu[f(x)]=f(y);
}

int main()
{
    scanf ("%d", &n);
    init ();

    return 0;
}

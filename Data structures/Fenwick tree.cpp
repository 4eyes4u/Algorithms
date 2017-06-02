/*
Data structure: Fenwick tree (Binary indexed tree)
Time complexities:
    Insert O(logn)
    Query O(logn)
Memory complexity:
    O(n)

    [where n is size of the tree]
*/

#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int bit[N];

void update (int x, int val)
{
    for (;x<N;x+=x&-x) bit[x]+=val;
}

int get (int x)
{
    int ret=0;
    for (;x;x-=x&-x) ret+=bit[x];
    return ret;
}

int main()
{
    return 0;
}

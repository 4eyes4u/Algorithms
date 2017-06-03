/*
Data structure: Segment tree
Time complexity: O(logn) per operaton [where n is size of array that segment tree is built on]
Memory complexity: O(n)

* * *
Merge operation is maximum.
*/

#include <bits/stdc++.h>
#define mid (left+right)/2
using namespace std;

const int N=1e5+10;

int st[4*N], n;

void init (int idx, int left, int right, int *a)
{
    if (left==right)
    {
        st[idx]=a[left];
        return;
    }

    init (2*idx, left, mid, a);
    init (2*idx+1, mid+1, right, a);
    st[idx]=max(st[2*idx], st[2*idx+1]);
}

void update (int idx, int left, int right, int x, int val)
{
    if (left==right)
    {
        st[idx]=val;
        return;
    }

    if (x<=mid) update (2*idx, left, mid, x, val);
    else update (2*idx+1, mid+1, right, x, val);
    st[idx]=max(st[2*idx], st[2*idx+1]);
}

int query (int idx, int left, int right, int l, int r)
{
    if (l<=left && right<=r) return st[idx];

    int ret=0;
    if (l<=mid) ret=max(ret, query(2*idx, left, mid, l, r));
    if (r>mid) ret=max(ret, query(2*idx+1, mid+1, right, l, r));
    return ret;
}

int main()
{
    return 0;
}

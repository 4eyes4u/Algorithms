/*
Data structure: Segment tree with lazy propagation
Time complexity: O(logn) per operation [where n is range]
Memory complexity: O(n) [where n is size of array that segment tree is built on]

* * *
Merge operation is sum on interval.
*/

#include <bits/stdc++.h>
#define mid (left+right)/2
using namespace std;

const int N=1e5+10;

long long st[4*N], lazy[4*N];
int n;

void propagate (int idx, int left, int right)
{
    if (lazy[idx])
    {
        st[idx]+=lazy[idx]*(right-left+1);
        if (left<right)
        {
            lazy[2*idx]+=lazy[idx];
            lazy[2*idx+1]+=lazy[idx];
        }
        lazy[idx]=0;
    }
}

void update (int idx, int left, int right, int l, int r, long long val)
{
    propagate (idx, left, right);
    if (left>right || left>r || right<l) return;

    if (l<=left && right<=r)
    {
        lazy[idx]+=val;
        propagate (idx, left, right);
        return;
    }

    update(idx, left, mid, l, r, val);
    update(2*idx, mid+1, right, l, r, val);
    st[idx]=st[2*idx]+st[2*idx+1];
}

long long query (int idx, int left, int right, int l, int r)
{
    propagate (idx, left, right);
    if (left>right || left>r || right<l) return 0;

    if (l<=left && right<=r) return st[idx];
    return query(2*idx, left, mid, l, r)+query(2*idx+1, mid+1, right, l, r);
}

int main()
{
    return 0;
}

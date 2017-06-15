/*
  Data structure: Implicit segment tree
  Time complexity: O(logu) per query [where u is size of universe U]
  Memory complexity: O(n*logu) [where n is number of added number and u is size of universe U]

* * *
Merge operation is maximum on interval.
*/

#include <bits/stdc++.h>
#define mid (left+right)/2
using namespace std;

struct Node
{
    Node *l, *r;
    int val;
    Node(): val(0), l(NULL), r(NULL) {}
    Node(int _val, Node *_l, Node *_r): val(_val), l(_l), r(_r) {}
};

const int u=1e9;

void update (Node *v, int left, int right, int x, int val)
{
    if (left==right)
    {
        v->val=val;
        return;
    }

    if (x<=mid)
    {
        if (v->l==NULL) v->l=new Node();
        update (v->l, left, mid, x, val);
    }
    else
    {
        if (v->r==NULL) v->r=new Node();
        update (v->r, mid+1, right, x, val);
    }

    if (v->l) v->val=max(v->val, (v->l)->val);
    if (v->r) v->val=max(v->val, (v->r)->val);
}

int query (Node *v, int left, int right, int l, int r)
{
    if (l<=left && right<=r) return v->val;

    int ret=0;
    if (l<=mid && v->l!=NULL) ret=query(v->l, left, mid, l, r);
    if (r>mid && v->r!=NULL) ret=max(ret, query(v->r, mid+1, right, l, r));
    return ret;
}

int main()
{
    Node *root=new Node();

    update (root, 1, u, 12345678, 100);
    printf ("%d\n", query(root, 1, u, 1, u));

    return 0;
}

/*
Data structure: Persistent segment tree
Time complexity: O(logu) per operation [where u is size of universe U]
Memory complexity: O(n*logu) [where n is number of states and u size of universe U]

* * *
Merge operation is maximum on interval.
*/

#include <bits/stdc++.h>
#define mid (left+right)/2
using namespace std;

const int N=1e5+10;
const int u=1e9;

struct Node
{
    Node *l, *r;
    int val;
    Node(): val(0), l(NULL), r(NULL) {}
    Node(int _val, Node *_l, Node *_r): val(_val), l(_l), r(_r) {}
};

void update (Node *v, Node *state, int left, int right, int x, int val)
{
    if (left==right)
    {
        v->val=val;
        return;
    }

    if (state!=NULL) v->l=state->l, v->r=state->r;

    if (x<=mid)
    {
        v->l=new Node();
        update (v->l, ((state!=NULL)?state->l:NULL), left, mid, x, val);
    }
    else
    {
        v->r=new Node();
        update (v->r, ((state!=NULL)?state->r:NULL), mid+1, right, x, val);
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
    vector<Node *> roots(N);
    roots[0]=new Node();

    return 0;
}

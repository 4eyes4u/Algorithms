/*
    Name: Implicit segment tree

    Time complexity: O(logN) per operation
    Space complexity: O(N * logU)

* * *
    Merge operation is maximum on interval.
*/

#include <bits/stdc++.h>
using namespace std;

const int U = 1e9;

struct Node {
    Node *l, *r;
    int val;
};

Node *root;

int get(Node *v) {
    return v ? v->val : 0;
}

void update(Node **v, int left, int right, int x, int val) {
    if (!*v)
        *v = new Node();

    if (left == right) {
        (*v)->val = val;
        return;
    }

    int mid = (left + right) / 2;
    if (x <= mid)
        update(&(*v)->l, left, mid, x, val);
    else
        update(&(*v)->r, mid + 1, right, x, val);

    (*v)->val = max(get((*v)->l), get((*v)->r));
}

int query(Node *v, int left, int right, int l, int r) {
    if (!v)
        return 0;
    if (l <= left && right <= r)
        return v->val;
    
    int mid = (left + right) / 2, ret = 0;
    if (l <= mid)
        ret = max(ret, query(v->l, left, mid, l, r));
    if (r > mid)
        ret = max(ret, query(v->r, mid + 1, right, l, r));
    return ret;

}

int main() {
    update(&root, 1, U, 12345678, 100);
    // output should be 100
    printf("%d\n", query(root, 1, U, 1, U));
 
    return 0;
}

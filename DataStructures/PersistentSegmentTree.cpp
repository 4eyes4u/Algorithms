/*
    Name: Persistent segment tree

    Time complexity: O(logU)
    Space complexity: O(N * logU)

* * *
    Merge operation is 'max'.
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int U = 1e9;

struct Node {
    Node *l, *r;
    int val;
};

int get(Node *v) {
    return v ? v->val : 0;
}

void update(Node **v, Node *state, int left, int right, int x, int val) {
    if (*v == nullptr)
        *v = new Node();

    if (left == right) {
        (*v)->val = val;
        return;
    }

    if (state) {
        (*v)->l = state->l;
        (*v)->r = state->r;
    }

    int mid = (left + right) / 2;
    if (x <= mid)
        update(&(*v)->l, state ? state->l : nullptr, left, mid, x, val);
    else
        update(&(*v)->r, state ? state->r : nullptr, mid + 1, right, x, val);

    (*v)->val = max(get((*v)->l), get((*v)->r));
}

int query (Node *v, int left, int right, int l, int r) {
    if (!v)
        return 0;

    if (l <= left && right <= r)
        return v->val;

    int ret = 0, mid = (left + right) / 2;
    if (l <= mid)
        ret = query(v->l, left, mid, l, r);
    if (r > mid )
        ret = max(ret, query(v->r, mid + 1, right, l, r));
    return ret;
}

int main() {    
    Node *root1 = new Node();
    update(&root1, nullptr, 1, U, 5, 10);

    Node *root2 = new Node();
    update(&root2, root1, 1, U, 5, 7);

    Node *root3 = new Node();
    update(&root3, root1, 1, U, U, 20);

    // output should be '10, 7, 20' respectively
    printf("%d\n", query(root1, 1, U, 1, U));
    printf("%d\n", query(root2, 1, U, 1, U));
    printf("%d\n", query(root3, 1, U, 1, U));

    return 0;
}

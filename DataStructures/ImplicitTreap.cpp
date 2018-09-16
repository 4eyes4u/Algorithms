/*
    Name: Implicit treap

    Time complexity: O(logN) per operation
    Space complexity: O(N)

* * *
    Merge operation is 'min' + 'swap'.
*/

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Node {
    Node *l, *r;
    int key, size, pr, val;
    bool rev;

    Node(int key, int pr) {
        this->key = key;
        this->pr = pr;
        this->size = 1;
        this->rev = 0;
        this->val = key;
        this->l = nullptr;
        this->r = nullptr;
    }
} *root;

int get_size(Node *v) {
    return v ? v->size : 0;
}

int get_val(Node *v) {
    return v ? v->val : INF;
}

void update(Node *v) {
    if (v) {
        v->size = 1 + get_size(v->l) + get_size(v->r);
        v->val = min(v->key, min(get_val(v->l), get_val(v->r)));
    }
}

void propagate(Node *v) {
    if (v && v->rev) {
        swap(v->l, v->r);
        if (v->l)
            v->rev ^= 1;
        if (v->r)
            v->rev ^= 1;
        v->rev = 0;
    }
}

void merge(Node *&v, Node *l, Node *r) {
    propagate(l);
    propagate(r);

    if (!l)
        v = r;
    else if (!r)
        v = l;
    else if (l->pr > r->pr) {
        merge(l->r, l->r, r);
        v = l;
    }
    else {
        merge(r->l, l, r->l);
        v = r;
    }

    update(v);
}

void split(Node *&v, Node *&l, Node *&r, int key, int add = 0) {
    propagate(v);
    if (!v) {
        l = r = nullptr;
        return;
    }

    int implicit_key = 1 + add + get_size(v->l);
    if (key <= implicit_key) {
        split(v->l, l, v->l, key, add);
        r = v;
    }
    else {
        split(v->r, v->r, r, key, 1 + add + get_size(v->r));
        l = v;
    }

    propagate(v);
}

void reverse(Node *v, int l, int r) {
    Node *u1, *u2;
    split(v, v, u1, l, 0);
    split(u1, u1, u2, r - l + 1, 0);
    u1->rev ^= 1;
    merge(v, v, u1);
    merge(v, v, u2);
}

int query(Node *v, int l, int r) {
    Node *u1, *u2;
    split(v, v, u1, l, 0);
    split(u1, u1, u2, r - l + 1, 0);
    int ret = get_val(u1);
    merge(v, v, u1);
    merge(v, v, u2);
    
    return ret;
}

int main() {
    int n, q;
    scanf("%d%d", &n, &q);

    for (int i = 0, key; i < n; i++) {
        scanf("%d", &key);
        Node *to_add = new Node(key, rand());
        merge(root, root, to_add);
    }

    for (int i = 0, type, l, r; i < q; i++) {
        scanf("%d%d%d", &type, &l, &r);
        if (type == 0)
            reverse(root, l, r);
        else
            printf("%d\n", query(root, l, r));
    }

    return 0;
}

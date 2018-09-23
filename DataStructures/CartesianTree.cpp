/*
    Name: Cartesian tree (not to be confused with treap)

    Time complexity: O(N) for initialization
    Space complexity: O(N)

* * *
    Useful for constructing suffix tree, suffix array, treap etc.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node *l, *r, *p;
    int val, idx;

    Node(int val, int idx) {
        this->val = val;
        this->idx = idx;
        this->l = nullptr;
        this->r = nullptr;
        this->p = nullptr; 
    }
};

Node *root, *last;

void add(Node *v, Node *prev_parent, Node *prev) {
    if (!prev_parent) {
        v->l = prev;
        prev->p = v;
        root = v;
    }
    else if (prev_parent->val <= v->val) {
        prev_parent->r = v;
        v->l = prev;
        v->p = prev_parent;
        prev->p = v;
    }
    else add(v, prev_parent->p, prev_parent);
}

void add(int val, int idx) {
    Node *v = new Node(val, idx);

    if (!root)
        root = v;
    else if (last->val <= v->val) {
        v->p = last;
        last->r = v;
    }
    else add(v, last->p, last);

    last = v;
}

void in_order(Node *v) {
    if (!v) return;

    in_order(v->l);
    printf("%d\n", v->val);
    in_order(v->r);
}

int main() {
    add(9, 1);
    add(3, 2);
    add(7, 3);
    add(1, 4);
    add(8, 5);
    add(12, 6);
    add(10, 7);
    add(20, 8);
    add(15, 9);
    add(18, 10);
    add(5, 11);
    
    in_order(root);

    return 0;
}

/*
  Data structure: Implicit Treap
  Time complexity: O(logn) per operation (average) [where n is number of elements]
  Memory complexity: O(n) [where n is number of elements]

* * *
Support every objective function.

In given code maximum on interval and reverse interval are implemented.
*/

#include <bits/stdc++.h>
using namespace std;

class Treap {
private:
  struct Node {
    Node *l, *r;
    int priority, size, value, f;
    bool reverse;

    Node(int value = 0) {
      this->l = this->r = nullptr;
      this->priority = rand();
      this->size = 1;
      this->value = value;
      this->f = value;
      this->reverse = 0;
    }
  } * root;

  int size(Node *v) { return v ? v->size : 0; }

  int f(Node *v) { return v ? v->f : 0; }

  void update_size(Node *v) {
    if (v)
      v->size = size(v->l) + size(v->r) + 1;
  }

  void update_f(Node *v) {
    if (v)
      v->f = max(max(f(v->l), f(v->r)), v->value);
  }

  void propagate(Node *v) {
    if (v && v->reverse) {
      v->reverse = 0;
      swap(v->l, v->r);

      if (v->l)
        v->l->reverse ^= 1;
      if (v->r)
        v->r->reverse ^= 1;
    }
  }

  void split(Node *v, Node *&l, Node *&r, int key, int lager = 0) {
    if (!v)
      return void(l = r = nullptr);
    propagate(v);
    int implicit_key = lager + size(v->l);
    if (key > implicit_key) {
      split(v->r, v->r, r, key, implicit_key + 1);
      l = v;
    } else {
      split(v->l, l, v->l, key, lager);
      r = v;
    }

    update_size(v);
    update_f(v);
  }

  void merge(Node *&root, Node *l, Node *r) {
    propagate(l);
    propagate(r);
    if (!l || !r)
      root = l ? l : r;
    else if (l->priority < r->priority) {
      merge(l->r, l->r, r);
      root = l;
    } else {
      merge(r->l, l, r->l);
      root = r;
    }

    update_size(root);
    update_f(root);
  }

  void delete_treap(Node *v) {
    if (!v)
      return;
    delete_treap(v->l);
    delete_treap(v->r);
    delete (v);
  }

  void insert(Node *&root, Node *v, int pos) {
    Node *t1, *t2;
    split(root, t1, t2, pos);
    merge(t1, t1, v);
    merge(root, t1, t2);
  }

  void reverse(Node *root, int l, int r) {
    Node *t1, *t2, *t3;
    split(root, t1, t2, l);
    split(t2, t2, t3, r - l + 1);
    t2->reverse ^= 1;
    merge(root, t1, t2);
    merge(root, root, t3);
  }

  int query(Node *root, int l, int r) {
    Node *t1, *t2, *t3;
    split(root, t1, t2, l);
    split(t2, t2, t3, r - l + 1);
    int ret = t2->f;
    merge(root, t1, t2);
    merge(root, root, t3);
    return ret;
  }

  void print_treap(Node *v) {
    if (!v)
      return;
    print_treap(v->l);
    printf("%d\n", v->value);
    print_treap(v->r);
  }

public:
  Treap(int root_value) { root = new Node(root_value); }

  ~Treap() { delete_treap(this->root); }

  void insert(int value, int pos) { insert(this->root, new Node(value), pos); }

  void reverse(int l, int r) { reverse(this->root, l, r); }

  int query(int l, int r) { return query(this->root, l, r); }

  void print_treap() { print_treap(this->root); }
};

int main() {
  Treap *t = new Treap(5);
  t->insert(7, 1);
  t->insert(10, 2);
  t->insert(3, 3);
  t->insert(17, 4);

  printf("%d\n", t->query(0, 1));
  t->reverse(1, 3);
  printf("%d\n", t->query(0, 4));
  printf("%d\n", t->query(2, 3));
  printf("%d\n", t->query(0, 1));

  delete (t);

  return 0;
}

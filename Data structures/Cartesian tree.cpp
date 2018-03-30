/*
  Data structure: Cartesian tree
  Memory complexity: O(n) [whre n is number of nodes]

* * *

Useful for constructing suffix tree, suffix array, treap...
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
  Node *l, *r, *p;
  int val, idx;

  Node(): l(), r(), p(), val(), idx() {}
  Node(int _val, int _idx): l(), r(), p(), val(_val), idx(_idx) {}
};

class CartesianTree {
private:
  Node *root, *last;

  void add(Node *v, Node *prev_parent, Node *prev) {
    if (!prev_parent) {
      v -> l = prev;
      prev ->p = v;
      root = v;
    }
    else if (prev_parent -> val <= v -> val) {
      prev_parent -> r = v;
      v -> l = prev;
      v -> p = prev_parent;
      prev -> p = v;
    } else add(v, prev_parent -> p, prev_parent);
  }

  void in_order (Node *v) {
    if (v -> l) in_order(v -> l);
    printf("%d\n", v -> val);
    if (v -> r) in_order(v -> r);
  }
  
public:
  CartesianTree () {
    root = nullptr;
    last = nullptr;
  }

  void add(int val, int idx) {
    Node *v = new Node(val, idx);

    if (!root) root=v;
    else if (last -> val <= v->val) {
      v -> p = last;
      last -> r = v;
    } else add(v, last -> p, last);

    last = v;
  }

  void in_order() {
    in_order(root);
  }
};

int main() {
  CartesianTree *tree = new CartesianTree();

  tree -> add(9, 1);
  tree -> add(3, 2);
  tree -> add(7, 3);
  tree -> add(1, 4);
  tree -> add(8, 5);
  tree -> add(12, 6);
  tree -> add(10, 7);
  tree -> add(20, 8);
  tree -> add(15, 9);
  tree -> add(18, 10);
  tree -> add(5, 11);

  tree -> in_order();

  return 0;
}

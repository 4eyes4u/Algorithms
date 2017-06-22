/*
Data structure: Segment tree
Time complexity: O(logn) per operaton [where n is range]
Memory complexity: O(n) [where n is size of array that segment tree is built on]

* * *
Merge operation is maximum.
*/

#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
#define mid (left+right)/2

private:
  int *a, n;
public:
  SegmentTree (int size) {
    n=size;
    a=(int *)calloc(4*size, sizeof(int));
  }

  void init (int idx, int left, int right, int *b) {
    if (left==right) {
      a[idx]=b[left];
      return;
    }

    init(2*idx, left, mid, b);
    init(2*idx+1, mid+1, right, b);
    a[idx]=max(a[2*idx], a[2*idx+1]);
  }

  void update (int idx, int left, int right, int x, int val) {
    if (left==right) {
      a[idx]=val;
      return;
    }

    if (x<=mid) update (2*idx, left, mid, x, val);
    else update (2*idx+1, mid+1, right, x, val);
    a[idx]=max(a[2*idx], a[2*idx+1]);
  }

  int query (int idx, int left, int right, int l, int r) {
    if (l<=left && right<=r) return a[idx];

    int ret=0;
    if (l<=mid) ret=max(ret, query(2*idx, left, mid, l, r));
    if (r>mid) ret=max(ret, query(2*idx+1, mid+1, right, l, r));
    return ret;
  }

  int get_size () {
    return n;
  }
};

int main() {
  SegmentTree *st=new SegmentTree(1000);

  int n=st->get_size();
  st->update(1, 1, n, 5, 1000);
  st->update(1, 1, n, 1, 10);
  st->update(1, 1, n, 512, 256);

  printf ("%d\n", st->query(1, 1, n, 1, 1000));
  printf ("%d\n", st->query(1, 1, n, 200, 600));
  printf ("%d\n", st->query(1, 1, n, 1, 4));

  return 0;
}

/*
  Data structure: Fenwick tree (Binary indexed tree)
  Time complexity: O(logn) per operation [where n is range]
  Memory complexity: O(n) [where n is size of the tree]
*/

#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
private:
  int *a, n;
public:
  FenwickTree (int size) {
    n=size;
    a=(int *)calloc(n, sizeof(int));
  }

  void add (int x, int val) {
    for (;x<=n;x+=x&-x) a[x]+=val;
  }

  int get (int x) {
    int ret=0;
    for (;x>0;x-=x&-x) ret+=a[x];
    return ret;
  }
};

int main() {
  FenwickTree *bit=new FenwickTree(100);

  bit->add(5, 1);
  bit->add(10, 2);
  bit->add(20, 3);

  printf ("%d\n", bit->get(50));
  printf ("%d\n", bit->get(15));
  printf ("%d\n", bit->get(10));

  return 0;
}

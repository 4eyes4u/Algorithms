/*
  Data structure: Fenwick tree [2D]
  Time complexity: O(logn*logm) per operation [where n is range of 1st and m is range of 2nd dimension]
  Memory complexity: O(n*m) [where is size of 1st and m size of 2nd dimension]
*/

#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
private:
  int **a, n, m;

  int get (int row, int c) {
    int ret=0;
    for (;row>0;row-=row&-row) {
      int col=c;
      for (;col>0;col-=col&-col) ret+=a[row][col];
    }

    return ret;
  }
public:
  FenwickTree (int sizeN, int sizeM) {
    n=sizeN;
    m=sizeM;
    a=(int **)calloc(n, sizeof(int *));
    for (int i=0;i<n;i++) a[i]=(int *)calloc(m, sizeof(int));
  }

  int update (int row, int c, int val) {
    for (;row<=n;row+=row&-row) {
      int col=c;
      for (;col<=m;col+=col&-col) a[row][col]+=val;
    }
  }

  int get (int r1, int c1, int r2, int c2) {
    return get(r2, c2)-get(r2, c1-1)-get(r1-1, c2)+get(r1-1, c1-1);
  }
};

int main() {
  FenwickTree *bit=new FenwickTree(100, 100);

  bit->update(10, 10, 1);
  bit->update(50, 10, 2);
  bit->update(10, 50, 3);

  printf ("%d\n", bit->get(1, 1, 80, 80));
  printf ("%d\n", bit->get(10, 10, 20, 20));
  printf ("%d\n", bit->get(8, 9, 50, 10));

  return 0;
}

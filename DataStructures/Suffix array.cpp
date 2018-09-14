/*
  Data strucutre: Suffix array
  Complexity:
    Init: O(n*log^2n) [where n is length of string]
    LCP: O(logn) [wehre n is length of string]
  Space: O(nlogn) [where n is length of string]
*/

#include <bits/stdc++.h>
using namespace std;

class SuffixArray {
private:
  int **a;
  pair<long long, int> *p;
  int n, m, k;

public:
  SuffixArray (char *s, int length) {
    n=length, m=ceil(log2(length))+1;
    a=(int **)calloc(n+10, sizeof(int *));
    for (int i=0;i<n;i++) a[i]=(int *)calloc(m+1, sizeof(int));
    p=(pair<long long, int> *)calloc(n, sizeof(pair<long long, int>));

    for (int i=0;i<n;i++) a[i][0]=s[i]+1;

    for (k=0;(1<<k)<2*n;k++) {
      for (int i=0;i<n;i++) p[i]={(1ll*a[i][k])<<30, i};
      for (int i=1<<k;i<n;i++) p[i-(1<<k)].first+=a[i][k];
      sort(p, p+n);

      int pos=1;
      for (int i=0;i<n;i++) {
        pos+=i && p[i-1].first<p[i].first;
        a[p[i].second][k+1]=pos;
      }
    }
  }

  int lcp (int u, int v) {
    int ret=0;

    for (int i=k-1;i>=0;i--) {
      int len=1<<i;
      if (u+len<=n && v+len<=n && a[u][i]==a[v][i]) u+=len, v+=len, ret+=len;
    }

    return ret;
  }
};

int main() {
  char s[] = "banana";
  SuffixArray *sa=new SuffixArray(s, 6);
  printf ("%d\n", sa->lcp(1, 3));

  return 0;
}

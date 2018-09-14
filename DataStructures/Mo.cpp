/*
  Data structure: Mo's algorithm
  Time complexity: O(sqrt(n))*X per operation [where n is number of elements and X is complexity of bucket update/query]
  Memory complexity: O(n) [were n is number of elements]

* * *
Calculating sum on interval.
*/

#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
const int Q=1e4+10;
const int BLOCKS=320;

struct Query
{
  int l, r, idx;
  Query(): l(), r(), idx() {}
  Query(int _l, int _r, int _idx): l(_l), r(_r), idx(_idx) {}
  bool operator < (const Query &q) const
  {
    return r<q.r;
  }
};

vector<Query> mo[BLOCKS+10];
int n, q, a[N];
long long sol[Q];

int main()
{
  scanf("%d%d", &n, &q);
  for (int i=1;i<=n;i++) scanf("%d", &a[i]);
  for (int i=0;i<q;i++)
  {
    int l, r;
    scanf("%d%d", &l, &r);
    mo[l/BLOCKS].push_back(*new Query(l, r, i));
  }

  for (int i=0;i<BLOCKS;i++) sort(mo[i].begin(), mo[i].end());

  for (int i=0;i<BLOCKS;i++)
  {
    if (mo[i].empty()) continue;

    int L=mo[i][0].l, R=L-1;
    long long sum=0;

    for (auto qxt: mo[i])
    {
      int l=qxt.l, r=qxt.r, idx=qxt.idx;

      while (R<r) sum+=1ll*a[++R];
      while (L<l) sum-=1ll*a[L++];
      while (L>l) sum+=1ll*a[--L];

      sol[idx]=sum;
    }
  }

  for (int i=0;i<q;i++) printf("%lld\n", sol[i]);

  return 0;
}

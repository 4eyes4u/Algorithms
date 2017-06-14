#include <bits/stdc++.h>
using namespace std;

struct Interval
{
  int l, r;
  Interval(): l(), r() {}
  Interval(int _l, int _r): l(_l), r(_r) {}
  bool operator < (const Interval &i) const
  {
    return r<i.r;
  }
};

int intervalScheduling (Interval *a, int n)
{
  sort (a, a+n);
  int ret=1, bound=a[0].r;

  for (int i=1;i<n;i++)
  {
    if (a[i].l>bound)
    {
      ret++;
      bound=a[i].r;
    }
  }

  return ret;
}

int main()
{
  return 0;
}

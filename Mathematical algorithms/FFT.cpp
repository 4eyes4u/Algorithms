/*
  Algorithm: Fast Fourier transform
  Complexity: Theta(n*logn) [where n is degree of polynomial]
*/

#include <bits/stdc++.h>
using namespace std;

namespace FFT
{
  typedef complex<double> base;
  const double pi=acos(-1.0);

  void DFT (vector<base> &a, bool inverse)
  {
    int n=a.size();

    for (int i=1, j=0;i<n;i++)
    {
      int bit=n>>1;
      for (;j>=bit;bit>>=1) j-=bit;
      j+=bit;
      if (i<j) swap(a[i], a[j]);
    }

    for (int len=2;len<=n;len<<=1)
    {
      double ang=2.0*pi/len*(inverse?-1.0:1.0);
      base wn(cos(ang), sin(ang));

      for (int i=0;i<n;i+=len)
      {
        base w(1.0);
        for (int j=0;j<len/2;j++)
        {
          base t=a[i+j+len/2]*w;
          a[i+j+len/2]=a[i+j]-t;
          a[i+j]+=t;
          w*=wn;
        }
      }
    }

    if (inverse) for (int i=0;i<n;i++) a[i]/=n;
  }

  vector<int> convolute (vector<int> a, vector<int> b)
  {
    vector<int> ret;
    int n=1;
    while (n<max(a.size(), b.size())) n<<=1;
    n<<=1;

    vector<base> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    fa.resize(n), fb.resize(n), ret.resize(n);

    DFT(fa, 0);
    DFT(fb, 0);
    for (int i=0;i<n;i++) fa[i]*=fb[i];

    DFT(fa, 1);
    for (int i=0;i<n;i++) ret[i]=(int)round(fa[i].real());

    while (ret.back()==0 && ret.size()) ret.pop_back();
    return ret;
  }
}

int main()
{
  int n, m;
  scanf ("%d%d", &n, &m);
  vector<int> a(n), b(m);
  for (int i=0;i<n;i++) scanf ("%d", &a[i]);
  for (int i=0;i<m;i++) scanf ("%d", &b[i]);

  vector<int> c=FFT::convolute(a, b);
  for (auto xt: c) printf ("%d ", xt);

  return 0;
}

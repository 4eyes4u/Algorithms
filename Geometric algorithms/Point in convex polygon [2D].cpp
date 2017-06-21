/*
  Algoithm: Check whether given pont belong to convex polygon
  Complexity: O(logn) [where n is number of vertices of polygon]

* * *
Convex polygon must be given in counter-clockwise order.
*/

#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef pair<int, int> pt;

long long ccw (pt o, pt a, pt b) {
  return (a.x-o.x)*(b.y-o.y)-(b.x-o.x)*(a.y-o.y);
}

bool in_triangle (pt a, pt b, pt c, pt t) {
  return ((ccw(a, b, t)>=0 && ccw(b, c, t)>=0 && ccw(c, a, t)>=0) || (ccw(a, b, t)<=0 && ccw(b, c, t)<=0 && ccw(c, a, t)<=0));
}

bool point_in_polygon (pt *p, int n, pt t) {
  p[n]=p[0];
  int l=1, r=n-1, mid, last=-1;

  while (l<=r) {
    mid=(l+r)/2;

    if (ccw(p[0], p[mid], t)>=0) {
      l=mid+1;
      last=mid;
    }
    else r=mid-1;
  }

  return last!=-1 && in_triangle(p[0], p[last], p[last+1], t);
}

int main() {
  pt p[]={{0, 0}, {2, 0}, {2, 2}, {0, 2}};
  pt t={1, 1};
  printf ("%d\n", point_in_polygon(p, 4, t));

  return 0;
}

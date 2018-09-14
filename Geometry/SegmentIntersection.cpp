/*
  Algorithm: Segment intersection
  Complexity: O(1)
*/

#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef pair<int, int> pt;

long long ccw (pt o, pt a, pt b)
{
  return 1ll*(a.x-o.x)*(b.y-o.y)-1ll*(b.x-o.x)*(b.y-o.y);
}

bool isCollinear (pt a, pt b, pt c)
{
  return ccw(a, b, c)==0;
}

bool isLeft (pt a, pt b, pt c)
{
  return ccw(a, b, c)>0;
}

bool opposite (pt a, pt b, pt c, pt d)
{
  return isLeft(a, b, c)!=isLeft(a, b, d);
}

bool isBetween (pt a, pt b, pt c)
{
  return min(a.x, b.x)<=c.x && c.x<=max(a.x, b.x) && min(a.y, b.y)<=c.y && c.y<=max(a.y, b.y);
}

bool intersect (pt a, pt b, pt c, pt d)
{
  if (isCollinear(a, b, c) && isBetween(a, b, c)) return true;
  if (isCollinear(a, b, d) && isBetween(a, b, d)) return true;
  if (isCollinear(c, d, a) && isBetween(c, d, a)) return true;
  if (isCollinear(c, d, b) && isBetween(c, d, b)) return true;
  return opposite(a, b, c, d) && opposite(c, d, a, b);
}

int main()
{
  return 0;
}

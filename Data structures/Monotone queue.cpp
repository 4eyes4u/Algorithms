/*
  Data structure: Monotone queue
  Complexity: O(1) amortized per operation

* * *
RMQ operation is minimum.
*/

#include <bits/stdc++.h>
using namespace std;

void add (deque<int> &dq, int x)
{
  while (!dq.empty() && dq.back()>x) dq.pop_back();
  dq.push_back(x);
}

int get_min (deque<int> &dq)
{
  if (!dq.empty()) return dq.front();
  return -1;
}

int main()
{
  return 0;
}

/*
  Algorithm: Longest increasing subsequence
  Complexity: O(n*logn) [where n is number of elements]
*/

#include <bits/stdc++.h>
using namespace std;

int LIS (int *a, int n, int *dp)
{
  vector<pair<int, int> > v;
  v.push_back({a[1], 1});
  dp[1]=1;

  for (int i=2;i<=n;i++)
  {
    dp[i]=1;

    int idx=lower_bound(v.begin(), v.end(), make_pair(a[i], 0))-v.begin();
    if (idx) dp[i]+=dp[v[idx-1].second];
    if (idx==v.size()) v.push_back({a[i], i});
    else v[idx]=min(v[idx], {a[i], i});
  }

  return v.size();
}

int main()
{
  return 0;
}

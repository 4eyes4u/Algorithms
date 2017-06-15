/*
  Algorithm: Kadane's algorithm
  Complexity: O(n) [where n is number of elements]
*/

#include <bits/stdc++.h>
using namespace std;

int Kadane (int *a, int n, long long *dp)
{
  dp[1]=a[1];

  for (int i=2;i<=n;i++) dp[i]=max(1ll*a[i], dp[i-1]+a[i]);

  return *max_element(dp+1, dp+n+1);
}

int main()
{
  return 0;
}

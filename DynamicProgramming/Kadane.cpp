/*
    Name: Find subarray with largest sum

    Time complexity: O(N)
    Space complexity: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int a[N];
long long dp[N];

long long Kadane(int n) {
    dp[1] = a[1];
    
    for (int i = 2; i <= n; i++)
  	    dp[i] = max(1ll * a[i], dp[i - 1] + a[i]);

    return *max_element(dp + 1, dp + n + 1);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);

    printf("%d\n", Kadane(n))
    
    return 0;
}

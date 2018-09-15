/*
    Algorithm: Longest increasing subsequence (LIS)
    Time complexity: O(N * logN)
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int a[N], dp[N];

int LIS(int n) {
    vector<pair<int, int>> v;
    v.emplace_back(a[1], 1);
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = 1;

        int idx = lower_bound(v.begin(), v.end(), make_pair(a[i], 0)) - v.begin();
        if (idx)
            dp[i] += dp[v[idx - 1].second];
            
        if (idx == v.size())
            v.emplace_back(a[i], i);
        else
            v[idx] = min(v[idx], {a[i], i});
    }

    return v.size();
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    
    printf("%d\n", LIS(n));

    return 0;
}

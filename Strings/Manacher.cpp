/*
    Name: Manacher's algorithm

    Time complexity: O(N)
    Space complexity: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

// char not present in the input
const char DUMMY = '#';

pair<int, int> Manacher(const string &s, string &pal) {
    int n = s.length();
    string aux(2*n + 1, DUMMY);
    for (int i = 0; i < n; i++)
        aux[2*i + 1] = s[i];

    vector<int> dp(2*n + 1, 0);
    int center = 0, r = 0;
    for (int i = 1; i <= 2*n; i++) {
        int mirror_i = 2*center - i;
        if (r > i) {
            dp[i] = min(r - i, dp[mirror_i]);
        }
        while (i + 1 + dp[i] <= 2*n &&
               aux[i + 1 + dp[i]] == aux[i - 1 - dp[i]]) {

            dp[i]++;
        }
        if (i + dp[i] > r) {
            center = i;
            r = i + dp[i];
        }
    }

    int pal_len = 0, pal_center = 0;
    for (int i = 0; i <= 2*n; i++) {
        if (dp[i] > pal_len) {
            pal_len = dp[i];
            pal_center = i;
        }
    }
    pal = s.substr((pal_center - pal_len) / 2, pal_len);

    return {pal_len, pal_center};
}

int main() {
    string s;
    cin >> s;
    string pal;
    auto ret = Manacher(s, pal);
    cout << pal << endl;

    return 0;
}
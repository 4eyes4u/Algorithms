/*
    Name: Rolling hash

    Time complexity:
        -O(N + logMOD) for initialization
        -O(1) for substrings' hash

* * *
    Prime should be several magnitudes lower than moduo.
    Several hash functions can be applied in order to reduce number of collisions.
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int P = 131;
const int MOD = 1e9 + 7;

char s[N];
int h[N], p[N], inv[N];

int mod_pow(int x, int pw, int MOD) {
    int ret = 1;
    while (pw) {
        if (pw & 1)
            ret = (1ll * ret * x) % MOD;
        pw >>= 1;
        x = (1ll * x * x) % MOD;
    }

    return ret;
}

void precalc_powers(int n) {
    p[0] = 1;
    p[1] = P;
    inv[0] = 1;
    inv[1] = mod_pow(P, MOD - 2, MOD);

    for (int i = 1; i < n; i++) {
        p[i] = (1ll * p[i - 1] * P) % MOD;
        inv[i] = (1ll * inv[i - 1] * inv[1]) % MOD;
    }
} 

void init(int n) {
    precalc_powers(n);

    h[0] = s[0];
    for (int i = 1; i < n; i++) {
        h[i] = (1ll * s[i] * p[i]) % MOD;
        h[i] += h[i - 1];
        
        if (h[i] >= MOD)
            h[i] -= MOD;
    }
}

int get_substring(int l, int r) {
    int val = h[r] - h[l - 1] + MOD;
    if (val >= MOD)
        val -= MOD;

    if (l)
        val = (1ll * val * inv[l - 1]) % MOD;
    
    return val;
}

int main() {
    scanf("%s", s);
    int n = strlen(s);
    init(n);

    printf("%d\n", get_substring(0, n - 1));

    return 0;
}
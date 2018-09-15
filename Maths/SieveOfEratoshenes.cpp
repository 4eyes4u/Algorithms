/*
    Name: Sieve of Eratoshenes
    
    Time complexity:
        -O(N * loglogN) initialization
        -O(logX) factorization
    Space complexity: O(N)

* * *
    For every number calculating smallest prime that divides it.
    Number X is prime if p[X] = X.
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int B = 1e5;

int p[N];

void init(int n) {
    for (int i = 3; i <= n; i += 2) {
        p[i - 1] = 2;

        if (!p[i]) {
            p[i] = i;
            if (i <= sqrt(n) + 1)
                for (int j = i * i; j <= n; j += i)
                    if (!p[j])
                        p[j] = i;
        }
    }
}

void factor(int x, vector<int> &factors) {
    while (x > 1) {
        factors.emplace_back(p[x]);
        x /= p[x];
    }
}

int main() {
    int n;
    scanf("%d", &n);
    init(n);

    vector<int> factors = {};
    factor(360, factors);
    for (auto prime : factors)
        printf("%d\n", prime);

    return 0;
}

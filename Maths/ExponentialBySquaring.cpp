/*
    Name: Exponential by squaring & modular inverse

    Time complexity: O(logN)
    Space compleity: O(1)

* * *
    For calculating modular inverse, moduo HAS TO BE prime.
*/

#include <bits/stdc++.h>
using namespace std;

long long mod_pow(long long x, long long pw, long long mod) {
    long long ret = 1;
    
    while (pw) {
        if (pw & 1)
            ret = (ret * x) % mod;
        pw >>= 1;
        x = (x * x) % mod;
    }

    return ret;
}

long long inverse(long long x, long long mod) {
    return mod_pow(x, mod - 2, mod);

}
int main() {
    return 0;
}

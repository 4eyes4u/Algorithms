/*
  Algorithm: Exponential by sqaring & modular inverse
  Complexity: O(logn) [where n is given number]

* * *
For calculating modular inverse moduo has to be prime number.
*/

#include <bits/stdc++.h>
using namespace std;

long long mod_pow (long long x, long long pw, long long mod) {
  long long ret = 1;
  while (pw) {
    if (pw & 1) ret = (ret * x) % mod;
    pw >>= 1;
    x = (x * x) % mod;
  }
  return ret;
}

long long inv (long long x, long long mod) {
  return mod_pow(x, mod-2, mod);
}

int main() {
  return 0;
}

/*
    Algorithm: Eucledian algorithm
    Complexity: O(logn)
*/

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

int main() {
    printf("%d\n", gcd(12, 20));
    
    return 0;
}
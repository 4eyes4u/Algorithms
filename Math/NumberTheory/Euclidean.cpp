/*
    Name: Eucledian algorithm
    
    Time complexity: O(logN)
    Space complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}

int main() {  
    return 0;
}
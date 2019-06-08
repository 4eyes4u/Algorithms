/*
    Name: Extended Euclidean algorithm

    Time complexity: O(logN)
    Space complexity: O(1)
*/

#include <iostream>
#include <assert.h>

int extended_euclidean(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1, y = 0;
        
        return a;
    }

    int x0, y0;
    int d = extended_euclidean(b, a % b, x0, y0);
    x = y0, y = x0 - y0 * (int)(a / b);

    return d;
}

int main() {
    int a, b;
    std::cin >> a >> b;
    
    int x, y;
    int d = extended_euclidean(a, b, x, y);
    assert(a*x + b*y - d == 0);

    return 0;
}
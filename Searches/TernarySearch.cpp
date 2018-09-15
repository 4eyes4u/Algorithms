/*
    Name: Ternary search

    Time complexity: O(logN)
    Space complexity: O(1)

* * *
    Function HAS TO BE unimodal.
    Implemented function has minimum.
*/

#include <bits/stdc++.h>
using namespace std;

double f(double x) {
    return x * x - 5 * x + 6;
}

double ternary_search(double l, double r, int iterations = 300) {
    while (iterations--) {
        double left_third = (2 * l + r) / 3;
        double right_rhird = (l + 2 * r) / 3;
        
        if (f(left_third) > f(right_rhird))
            l = left_third;
        else
            r = right_rhird;
    }

    return f((l + r) / 2);
}

int main() {
    printf("%lf\n", ternary_search(-5, 10));

    return 0;
}
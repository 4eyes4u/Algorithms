/*
    Name: Generating basis of Z^{DIM}_2

    Time complexity: O(DIM) per operation
    Space complexity: O(DIM)

* * *
    Implemented vector space has DIM = 32.
    First element is the biggest.
    Linear combination is equivalent to taking minimum.
*/


#include <bits/stdc++.h>
using namespace std;

vector<int> basis;

void insert(int x) {
    if (basis.empty())
        basis.emplace_back(x);
    
    for (auto e : basis)
        x = min(x, x ^ e);

    if (x) {
        basis.emplace_back(x);

        for (int i = basis.size() - 1; i > 0; i--)
            if (basis[i] > basis[i - 1])
                swap(basis[i], basis[i - 1]);
    }
}

int get_min(int x) {
    for (auto e : basis)
        x = min(x, x ^ e);

    return x;
}

int main() {
    return 0;
}
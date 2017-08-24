/*
    Algorithm: Generating basis of Z^{n}_2
    Complexity: O(n) per operation

    * * *
    Implemented vector space has DIM = 32 (int).
*/

#include <bits/stdc++.h>
using namespace std;

namespace VectorSpace {
    const int DIM = 32;

    int basis[DIM], d = 0;

    void insert(int x) {
        if (!d) return void(basis[d++] = x);

        for (int i = 0; i < d; i++) x = min(x, x ^ basis[i]);
        
        if (x) {
            basis[d++] = x;
            for (int i = d - 1; i > 0; i--)
                if (basis[i] > basis[i - 1])
                    swap(basis[i], basis[i - 1]);
        }
    }

    int get_min(int x) {
        for (int i = 0; i < d; i++) x = min(x, x ^ basis[i]);
        return x;
    }
}

int main() {
    VectorSpace::insert(4);
    VectorSpace::insert(7);
    VectorSpace::insert(8);
    VectorSpace::insert(12);
    VectorSpace::insert(17);

    for (int i = 0; i < VectorSpace::d; i++) printf("%d\n", VectorSpace::basis[i]);
    printf("%d\n", VectorSpace::get_min(22));

    return 0;
}
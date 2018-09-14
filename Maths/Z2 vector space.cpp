/*
    Algorithm: Generating basis of Z^{n}_2
    Complexity: O(n) per operation [where n is dimension]

    * * *
    Implemented vector space has DIM = 32 (int).
    First element is the biggest.
    Getting min is equivalent to making linear combination.
*/


#include <bits/stdc++.h>
using namespace std;

class VectorSpace {
private:
    vector<int> basis;

public:
    VectorSpace () {
        basis = vector<int>();
    }

    void insert(int x) {
        if (basis.empty()) return void(basis.emplace_back(x));

        for (auto e: basis) x = min(x, x ^ e);

        if (x) {
            basis.push_back(x);

            for (int i = basis.size() - 1; i > 0; i--)
                if (basis[i] > basis[i - 1])
                    swap(basis[i], basis[i - 1]);
        }
    }

    int get_min (int x) {
        for (auto e: basis) x = min(x, x ^ e);

        return x;
    }

    int kth (int k) {
        if (k > basis.size()) return -1;
        return basis[k - 1];
    }
};

int main() {
    VectorSpace *Z2 = new VectorSpace();
    Z2 -> insert(4);
    Z2 -> insert(7);
    Z2 -> insert(8);
    Z2 -> insert(12);
    Z2 -> insert(17);

    for (int i = 1; i <= 10; i++) printf("%d\n", Z2 -> kth(i));
    printf("%d\n", Z2 -> get_min(22));

    return 0;
}
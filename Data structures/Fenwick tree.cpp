/*
    Data structure: Fenwick tree (Binary indexed tree)
    Time complexity: O(logn) per operation [where n is range]
    Memory complexity: O(n) [where n is size of the tree]
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int bit[N], n;

void update(int x, int val) {
    for (; x < N; x += x & -x)
        bit[x] += val;
}

int get(int x) {
    int ret = 0;

    for (; x; x -= x & -x)
        ret += bit[x];

    return ret;
}

int main() {
    // scanf("%d", &n);
    n = 10;

    update(5, 6);
    update(1, 12);
    update(7, 3);
    
    printf("%d\n", get(10)); // should be 21
    printf("%d\n", get(8) - get(4)); // should be 9

    return 0;
}

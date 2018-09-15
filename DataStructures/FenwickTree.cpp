/*
    Name: Fenwick tree (Binary indexed tree)

    Time complexity: O(logN) per operation
    Space complexity: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int bit[N];

void update(int n, int x, int val) {
    for (; x <= n; x += x & -x)
        bit[x] += val;
}

int get(int x) {
    int ret = 0;

    for (; x; x -= x & -x)
        ret += bit[x];

    return ret;
}

int main() {
    int n;
    scanf("%d", &n);

    update(n, 10, 50);
    update(n, 5, 12);
    // for n > 15 output should be 50
    printf("%d\n", get(15) - get(8));

    return 0;
}

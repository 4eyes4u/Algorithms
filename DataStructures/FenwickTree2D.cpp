/*
    Name: Fenwick tree [2D]

    Time complexity: O(logN * logM) per operation
    Space complexity: O(N * M)
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
const int M = 1e3 + 10;

int bit[N][M], n, m;

void update(int row, int c, int val) {
    for (; row <= n; row += row & -row) {
        int col = c;

        for (; col <= m; col += col & -col)
            bit[row][col] += val;
    }
}

int get(int row, int c) {
    int ret = 0;

    for (; row; row -= row & -row) {
        int col = c;

        for (; col; col -= col & - col)
            ret += bit[row][col];
    }

    return ret;
}

int get(int r1, int c1, int r2, int c2) {
    return get(r2, c2) - get(r2, c1 - 1) - get(r1 - 1, c2) + get(r1 - 1, c1 - 1);
}

int main() {
    // scanf("%d%d", &n, &m);
    n = 5, m = 8;

    update(2, 3, 4);
    update(5, 5, 10);
    update(1, 8, 2);

    printf("%d\n", get(1, 1, 5, 8)); // should be 16
    printf("%d\n", get(2, 3, 2, 3)); // should be 4
    printf("%d\n", get(4, 4, 4, 4)); // shoulde be 0

    return 0;
}

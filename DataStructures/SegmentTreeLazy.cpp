/*
    Name: Segment tree with lazy propagation

    Time complexity: O(logN) per operation
    Space complexity: O(N)

* * *
    Merge operation is 'sum'.
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

long long st[4 * N], lazy[4 * N];

void propagate(int idx, int left, int right) {
    if (lazy[idx]) {
        st[idx] += lazy[idx] * (right - left + 1);

        if (left < right) {
            lazy[2 * idx] += lazy[idx];
            lazy[2 * idx + 1] += lazy[idx];
        }

        lazy[idx] = 0;
    }
}

void update(int idx, int left, int right, int l, int r, int val) {
    propagate(idx, left, right);
    if (left > right || left > r || right < l)
        return;

    if (l <= left && right <= r) {
        lazy[idx] += val;
        propagate(idx, left, right);
        return;
    }

    int mid = (left + right) / 2;
    update(2 * idx, left, mid, l, r, val);
    update(2 * idx + 1, mid + 1, right, l, r, val);
    st[idx] = st[2 * idx] + st[2 * idx + 1];
}

long long query (int idx, int left, int right, int l, int r) {
    propagate (idx, left, right);
    if (left > right || left > r || right < l)
        return 0;

    if (l <= left && right <= r)
        return st[idx];

    int mid = (left + right) / 2;
    return query(2 * idx, left, mid, l, r) + query(2 * idx + 1, mid + 1, right, l, r);
}

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    while (q--) {
        int type, l, r;
        scanf("%d%d%d", &type, &l, &r);

        if (type == 1) {
            int val;
            scanf("%d", &val);
            update(1, 1, n, l, r, val);
        }
        else
            printf("%lld\n", query(1, 1, n, l, r));
    }
    return 0;
}

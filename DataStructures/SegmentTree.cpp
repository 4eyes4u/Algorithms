/*
    Name: Segment tree

    Time complexity:
        -O(logN) per operation
        -O(N * logN) for initialization
    Space complexity: O(N)

* * *
    Merge operation is 'max'.
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int a[N], st[4 * N];

void init(int idx, int left, int right) {
	if (left == right) {
		st[idx] = a[left];
		return;
	}
	
    int mid = (left + right) / 2;
	init(2 * idx, left, mid);
	init(2 * idx + 1, mid + 1, right);
}

void update(int idx, int left, int right, int pos, int val) {
	if (left == right) {
		st[idx] = val;
		return;
	}
	
    int mid = (left + right) / 2;
	if (pos <= mid)
        update(2 * idx, left, mid, pos, val);
	else
        update(2 * idx + 1, mid + 1, right, pos, val);
	st[idx] = max(st[2 * idx], st[2 * idx + 1]);
}

int query(int idx, int left, int right, int l, int r) {
	if (left <= l && right <= r) return st[idx];
	
	int ret = 0, mid = (left + right) / 2;
	if (l <= mid)
        ret = max(ret, query(2 * idx, left, mid, l, r));
	if (r > mid)
        ret = max(ret, query(2 * idx + 1, mid + 1, right, l, r));
	return ret;
}

int main() {
    int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
		
	init(1, 1, n);
	printf("%d\n", query(1, 1, n, 1, n));

	return 0;
}

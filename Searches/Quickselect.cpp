/*
    Name: Quickselect

    Time complexity:
        -O(N ^ 2) worst case
        -O(N) average case
    Space complexity: O(1)

* * *
    Order of elements IS NOT preserved.
    Indexed from zero -- smallest number is on position 0.
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int a[N];

int quick_select(int l, int r, int k) {
    if (l == r)
        return a[l];

    int pivot = a[l], pos = l;
    for (int i = l + 1; i <= r; i++) {
        if (a[i] < pivot) {
            swap(a[i], a[pos++]);
            swap(a[i], a[pos]);
        }
    }

    if (pos - l < k)
        return quick_select(pos + 1, r, k - (pos - l + 1));
    else if (pos - l == k)
        return pivot;
    else
        return quick_select(l, pos - 1, k);
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    assert(n > k);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    
    printf("%d\n", quick_select(0, n - 1, k));

    return 0;
}
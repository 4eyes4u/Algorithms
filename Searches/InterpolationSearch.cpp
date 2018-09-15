/*
    Name: Interpolation search

    Time complexity:
        -O(N) worst case
        -O(loglogN) average case
    Space complexity: O(1)

* * *
    Array HAS TO BE monotone.
    Works fast if elements are uniformly distributed.
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int a[N];

int interpolation_search(int n, int x) {
    int l = 0, r = n - 1;

    while (a[l] != a[r] && x >= a[l] && x <= a[r]) {
        int mid = l + (x - a[l]) * (r - l) / (a[r] - a[l]);

        if (a[mid] < x)
            l = mid + 1;
        else if (a[mid] > x)
            r = mid - 1;
        else
            return mid;
    }

    if (x == a[l])
        return l;
    return -1;
}

int main() {
    int n, x;
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    
    printf("%d\n", interpolation_search(n, x));

    return 0;
}
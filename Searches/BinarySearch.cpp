/*
    Name: Binary search

    Time complexity: O(logN)
    Space complexity: O(1)

* * *
    Searching for rightmost number smaller than X in given range.
    Array HAS TO BE monotone.
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int a[N];

int binary_search(int l, int r, int x) {
    int ret = -1;
    
    while (l <= r) {
        int mid = (l + r) / 2;

        if (a[mid] <= x) {
            ret = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }

    return ret;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    
    printf("%d\n", binary_search(0, n - 1, 20));

    return 0;
}

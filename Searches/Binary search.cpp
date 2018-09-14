/*
    Algorithm: Binary search
    Complexity: O(logn) [where n is length of range]

* * *
Searching for rightmost number smaller than x in given range.
*/

#include <bits/stdc++.h>
using namespace std;

int binary_search(int *a, int left, int right, int x) {
    int ret = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2; // in case of overflow
        if (a[mid] <= x) ret = mid, left = mid + 1;
        else right = mid - 1;
    }

    return ret;
}

int main() {
    int a[] = {1, 3, 3, 3, 5, 6, 7, 8, 9, 10};
    printf("%d\n", binary_search(a, 0, sizeof(a) / sizeof(int), 5)); // output should be 4

    return 0;
}

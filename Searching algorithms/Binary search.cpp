/*
Algorithm: Binary search
Complexity: O(logn) [where n is length of range]
*/

#include <bits/stdc++.h>
using namespace std;

int binarySearch (int *a, int left, int right, int x)
{
    int ret=-1;
    while (left<=right)
    {
        int mid=left+(right-left)/2;
        if (a[mid]<=x) ret=mid, right=mid-1;
        else left=mid+1;
    }

    return ret;
}

int main()
{
    return 0;
}

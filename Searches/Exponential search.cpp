/*
Algorithm: Exponential search
Complexity: O(logi) [where i is index of searched element]
*/

#include <bits/stdc++.h>
using namespace std;

int expSearch (int *a, int x)
{
    int range=1;
    while (a[range]<x) range<<=1;
    return range;
}

int main()
{
    return 0;
}

/*
Algorithm: Using bitset to speed up DP solution
Time and memory complexity: O(n/c) per operation [where n is size and c is constant which is 8, 16 or 32 depending on compiler]

* * *
Testing whether given sum can be obtained by using added numbers at most once.
*/

#include <bits/stdc++.h>
using namespace std;

const int N=1e6+10;

bitset<N> dp;
int q;

int main()
{
    dp.set(0);

    scanf ("%d", &q);
    while (q--)
    {
        int type, x;
        scanf ("%d%d", &type, &x);

        if (type==1)
        {
            for (int i=1;i<=x;i<<=1) dp|=dp<<i;
            dp|=dp<<x;
        }
        else printf ("%d\n", dp.test(x));
    }

    return 0;
}

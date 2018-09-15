/*
    Name: Using bitset to speed up DP solution
    
    Time complexity: O(N / C)
    Space complexity: O(N / C)

* * *
    C is usually 16.
    Testing whether sum can be obtained by using given numbers at most once.
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;

bitset<N> dp;

int main() {
    dp.set(0);

    int q;
    scanf("%d", &q);
    while (q--) {
        int type, x;
        scanf("%d%d", &type, &x);

        if (type==1) {
            for (int i = 1; i <= x; i <<= 1)
                dp |= dp << i;
            dp |= dp << x;
        }
        else
            printf("%d\n", dp.test(x));
    }

    return 0;
}

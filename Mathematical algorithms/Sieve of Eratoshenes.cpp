/*
Algorithm: Sieve of Eratoshenes
Complexity: O(n*loglogn) [where n is upper bound]

* * *
For every number calculating smallest prime that divides it.
*/

#include <bits/stdc++.h>
using namespace std;

const int B=1e5;
const int N=1e5+10;

int mark[N];

void sieve ()
{
    for (int i=3;i<=B;i+=2)
    {
        mark[i-1]=2;
        if (!mark[i])
        {
            mark[i]=i;
            if (i<=sqrt(B)+1) for (int j=i*i;j<=B;j+=i) if (!mark[j]) mark[j]=i;
        }
    }
}

int main()
{
    return 0;
}

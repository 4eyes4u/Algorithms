#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

//Nalazenje prostih brojeva do broja A
//Slozenost: O(N log log N)

const int N=1e5+10;
bool mark[N];
vector<int> primes;

void sieve (int A)
{
    for (int i=2;i<=A;i+=2)
    {
        if (!mark[i])
        {
            primes.push_back(i);
            for (int j=i;j<=A;j+=i) mark[j]=true;
        }
    }
}

int main()
{

	return 0;
}

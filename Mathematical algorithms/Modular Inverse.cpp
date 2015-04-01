/*
    Opis: Modularni inverz | Stepenovanje kvadriranjem | Deljenje po modulu
    Slozenost: O(log N)
*/

#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

const ll MOD=1e9+7; //Modul

ll modPow (ll num, ll pow, ll mod)
{
    ll ret=1;
    while (pow)
    {
        if (pow&1)
        {
            ret=(ret*num)%mod;
        }
        pow>>=1;
        num=(num*num)%mod;
    }
    return ret;
}

ll modInv (ll num, ll mod)
{
    return mod_pow (num, mod-2, mod);
}

//deljenje po modulu
ll modDiv (ll up, ll down, ll mod)
{
    return up*modInv(down, mod);
}

int main()
{

	return 0;
}

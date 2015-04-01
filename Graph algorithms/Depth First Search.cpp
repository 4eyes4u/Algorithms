/*
    Opis: Pretraga grafa u dubinu
    Slozenost: O(V + E)
*/

#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N=1e5+10;

struct node
{
    vector<int> adj;
} g[N];

bool mark[N];

void dfs (int v)
{
    mark[v]=true;
    for (int i=0;i<g[v].adj.size();i++)
    {
        if (!mark[g[v].adj[i]])
        {
            dfs (g[v].adj[i]);
        }
    }
}

int main()
{

	return 0;
}

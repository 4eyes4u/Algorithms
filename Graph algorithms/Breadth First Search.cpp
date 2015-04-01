#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N=1e5+10;

struct node
{
    vector<int> adj;
} g[N];

bool mark[N];

void bfs (int start)
{
    queue<int> q;
    q.push(start);
    while (!q.empty())
    {
        int xt=q.front();
        q.pop();
        mark[xt]=true;
        for (int i=0;i<g[xt].adj.size();i++)
        {
            if (!mark[g[xt].adj[i]])
            {
                q.push(g[xt].adj[i]);
                mark[g[xt].adj[i]]=true;
            }
        }
    }
}

int main()
{

	return 0;
}

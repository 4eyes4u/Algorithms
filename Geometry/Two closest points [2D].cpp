/*
Algorithm: Finding two closest points in the set of points
Complexity: O(nlogn) [where n is number of pooints]
*/

#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
const double eps=1e-18;

struct pt
{
    double x, y;
    int idx;

    bool operator<(const pt &p) const
    {
        return (x<p.x-eps || ((x-p.x)<=eps && y<p.y-eps));
    }
};

pt a[N], aux[N];
pair<pt, pt> pts;
double sol=10000000.0;
int n;

double dist (pt a, pt b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

void update (pt a, pt b)
{
    double d=dist(a, b);
    if (d<sol-eps)
    {
        sol=d;
        pts={a, b};
    }
}

void solve (int l, int r)
{
    if (l>=r) return;
    if (r-l==1)
    {
        if (a[l].y>a[r].y+eps) swap (a[l], a[r]); //preparing for merge sort
        update (a[l], a[r]);
        return;
    }

    int mid=(l+r)/2;
    double separator=a[mid].x; //vertical separating line

    solve (l, mid);
    solve (mid+1, r);

    int L=l, R=mid+1, k=0;
    while (L<=mid || R<=r) //merge sort
    {
        if (L>mid || (R<=r && a[R].y<a[L].y-eps)) aux[k++]=a[R++];
        else aux[k++]=a[L++];
    }

    for (int i=l;i<=r;i++) a[i]=aux[i-l]; //sorted

    k=0;
    for (int i=l;i<=r;i++) if (abs(a[i].x-separator)<sol-eps) aux[k++]=a[i]; //getting rid of unnecessary points
    for (int i=0;i<k;i++) //making better solution
    {
        for (int j=i+1;j<k;j++) //maximum 5 iterations
        {
            if (aux[j].y-aux[i].y>=sol+eps) break;
            update(aux[i], aux[j]);
        }
    }
}

int main()
{
    scanf ("%d", &n);
    for (int i=1;i<=n;i++)
    {
        scanf ("%lf%lf", &a[i].x, &a[i].y);
        a[i].idx=i-1;
    }

    sort (a+1, a+n+1);

    solve(1, n);

    cout << min(pts.first.idx, pts.second.idx) << " " << max(pts.first.idx, pts.second.idx) << " " << fixed << setprecision(6) << sol;

    return 0;
}

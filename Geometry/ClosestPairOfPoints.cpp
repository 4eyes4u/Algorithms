/*
    Name: Finfing closest pair in the set of points

    Time complexity: O(N * logN)
    Space complexity: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const double INF = 1e18;
const double EPS = 1e-18;

struct Point {
    double x, y;

    bool operator < (const Point &other) const {
        if (x < other.x - EPS)
            return 1;
        if (abs(x - other.x) < EPS && y < other.y - EPS)
            return 1;
    }
} pts[N], aux[N];

pair<Point, Point> closest;
double sol = INF;

double dist(Point P, Point Q) {
    return sqrt(pow(P.x - Q.x, 2) + pow(P.y - Q.y, 2));
}

void update(Point P, Point Q) {
    double d = dist(P, Q);
    if (d < sol - EPS) {
        sol = d;
        closest = {P, Q};
    }
}

void solve(int l, int r) {
    if (l >= r)
        return;
    
    if (r - l == 1) {
        if (pts[l].y > pts[r].y + EPS)
            // preparing for merge sort
            swap(pts[l], pts[r]);
        update(pts[l], pts[r]);
        return;
    }

    int mid = (l + r) / 2;
    // vertical separating line
    double separator = pts[mid].x;

    solve(l, mid);
    solve(mid + 1, r);

    // merge sort
    int L = l, R = mid + 1, k = 0;
    while (L <= mid || R <= r) {
        if (L > mid || R <= r && pts[R].y < pts[L].y - EPS)
            aux[k++] = pts[R++];
        else
            aux[k++] = pts[L++];
    }

    // sorted
    for (int i = l; i <= r; i++)
        pts[i] = aux[i - l];

    // getting rid of unnecessary points
    k = 0;
    for (int i = l; i <= r; i++)
        if (abs(pts[i].x - separator) < sol - EPS)
            aux[k++] = pts[i];
    
    // making better solution
    for (int i = 0; i < k; i++) {
        // maximum 5 iterations of inner loop
        for (int j = i + 1; j < k; j++) {
            if (aux[j].y - aux[i].y >= sol + EPS)
                break;
            update(aux[i], aux[j]);
        }
    }
}

int main() {
    int n;
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lf%lf", &pts[i].x, &pts[i].y);

    sort(pts + 1, pts + n + 1);
    solve(1, n);

    printf("%lf %lf\n", closest.first.x, closest.first.y);
    printf("%lf %lf\n", closest.second.x, closest.second.y);
    printf("%.6lf\n", sol);

    return 0;
}

/*
    Name: Check whether point belong to convex polygon

    Time complexity: O(logN)
    Space complexity: O(N)

* * *
    Convex polygon must be given in counter-clockwise order.
*/

#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

const int N = 1e5 + 10;

struct Point {
    int x, y;
} pts[N];

long long ccw(Point O, Point A, Point B) {
    return 1ll * ((A.x - O.x)*(B.y - O.y) - (B.x - O.x)*(A.y - O.y));
}

bool in_triangle(Point A, Point B, Point C, Point P) {
    bool left = ccw(A, B, P) >= 0 && ccw(B, C, P) >= 0 && ccw(C, A, P) >= 0;
    bool right = ccw(A, B, P) <= 0 && ccw(B, C, P) <= 0 && ccw(C, A, P) <= 0;

    return left || right;
}

bool check(int n, Point P) {
    pts[n] = pts[0];
    int l = 1, r = n - 1, last = -1;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (ccw(pts[0], pts[mid], P) >= 0) {
            l = mid + 1;
            last = mid;
        }
        else r = mid - 1;
    }

    return last != -1 && in_triangle(pts[0], pts[last], pts[last + 1], P);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &pts[i].x, &pts[i].y);

    Point P = {0, 0};
    printf("%d\n", check(n, P));

    return 0;
}

/*
    Name: Convex hull of set of points (Andrew's algorithm)

    Time complexity: O(N * logN)
    Space complexity: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;

    bool operator < (const Point &other) const {
        if (x == other.x)
            return y < other.y;
        return x < other.x;
    }
};

vector<Point> pts;

long long ccw(Point O, Point A, Point B) {
    return 1ll * (A.x - O.x) * (B.y - O.y) - (B.x - O.x) * (A.y - O.y);
}

void convex_hull(vector<Point> &pts, vector<Point> &hull) {
    hull.clear();
    sort(pts.begin(), pts.end());

    for (int i = 0; i < 2; i++) {
        int init_size = hull.size();

        for (auto xt : pts) {
            while(hull.size() >= 2 + init_size && ccw(hull[hull.size() - 2], hull.back(), xt) <= 0)
                hull.pop_back();
            hull.emplace_back(xt);
        }

        hull.pop_back();
        reverse(pts.begin(), pts.end());
    }
}

int main() {
    return 0;
}

/*
   Algorithm: Andrew's monotone chain convex hull algorithm
   Complexity: O(n*logn) [where n is number of points]
 */

#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef pair<int, int> pt;

long long ccw(pt o, pt a, pt b) {
        return 1ll * (a.x - o.x) * (b.y - o.y) - 1ll * (b.x - o.x) * (a.y - o.y);
}

vector<pt> convexHull(vector<pt> pts) {
        vector<pt> hull;
        sort(pts.begin(), pts.end());

        for (int i = 0; i < 2; i++) {
                auto init_size = pts.size();

                for (auto xt : pts) {
                        while (hull.size() >= 2 + init_size && ccw(hull[hull.size() - 2], hull.back(), xt) <= 0)
                                hull.pop_back();
                        hull.push_back(xt);
                }

                hull.pop_back();
                reverse(pts.begin(), pts.end());
        }

        return hull;
}

int main() {
        return 0;
}

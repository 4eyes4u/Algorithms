/*
    Name: Jarvis march

    Time complexity: O(N * h)
    Space complexity: O(N)
*/

#include <iostream>
#include <algorithm>

struct Point {
    int x, y;

    friend std::ostream& operator << (std::ostream &strm, const Point &P) {
        return strm << "Point=[" << P.x << ", " << P.y << "]";
    }
};

long long cross_product(Point O, Point A, Point B) {
    return 1ll * ((A.x - O.x)*(B.y - O.y) - (B.x - O.x)*(A.y - O.y));
}

std::vector<Point> JarvisMarch(std::vector<Point> pts) {
    std::vector<Point> hull;
    
    std::swap(pts[0],
              *std::min_element(pts.begin(),
                                pts.end(),
                                [](const Point &p, const Point &q) {
                                    return p.x < q.x || p.x == q.x && p.y < q.y;
                                }));
    do {
        hull.emplace_back(pts[0]);
        std::swap(pts[0],
                  *std::min_element(pts.begin() + 1,
                                    pts.end(),
                                    [pts](const Point &p, const Point &q) {
                                        return cross_product(pts[0], p, q) > 0;
                                    }));
    }
    while (pts[0].x != hull[0].x || pts[0].y != hull[0].y);

    return hull;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Point> pts(n);
    for (Point &pt : pts) {
        std::cin >> pt.x >> pt.y;
    }

    auto hull = JarvisMarch(pts);
    for (Point &pt : hull) {
        std::cout << pt << std::endl;
    }

    return 0;
}
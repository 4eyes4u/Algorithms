/*
    Name: Graham scan

    Time complexity: O(N * logN)
    Space complexity: O(N)
*/

#include <iostream>
#include <algorithm>
#include <vector>

struct Point {
    int x, y;

    friend std::ostream& operator << (std::ostream &strm, const Point &P) {
        return strm << "Point=[" << P.x << ", " << P.y << "]";
    }

    static long long cross_product(Point O, Point A, Point B) {
        return 1ll * ((A.x - O.x)*(B.y - O.y) - (B.x - O.x)*(A.y - O.y));
    }
};

std::vector<Point> GrahamScan(std::vector<Point> pts) {
    std::swap(pts[0],
              *std::min_element(pts.begin(),
                                pts.end(),
                                [](const Point &p, const Point &q) {
                                    return p.x < q.x || p.x == q.x && p.y < q.y;
                                }));
    std::sort(pts.begin() + 1, pts.end(),
              [pts](const Point &p, const Point &q) {
                  return Point::cross_product(pts[0], p, q) > 0;
              });
            
    std::vector<Point> hull;
    for (Point &pt : pts) {
        while (hull.size() >= 2 &&
               Point::cross_product(hull[hull.size() - 2], hull[hull.size() - 1], pt) <= 0) {
            
            hull.pop_back();
        }

        hull.emplace_back(pt);
    }

    return hull;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Point> pts(n);
    for (Point &pt : pts) {
        std::cin >> pt.x >> pt.y;
    }

    auto hull = GrahamScan(pts);
    for (Point &pt : hull) {
        std::cout << pt << std::endl;
    }

    return 0;
}
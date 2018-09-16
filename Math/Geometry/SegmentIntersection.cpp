/*
    Name: Segment intersection in 2D

    Time complexity: O(1)
    Space complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

long long ccw(Point O, Point A, Point B) {
    return 1ll * (A.x - O.x) * (B.y - O.y) - (B.x - O.x) * (A.y - O.y);
}

bool is_collinear(Point A, Point B, Point C) {
    return ccw(A, B, C) == 0;
}

bool is_left(Point A, Point B, Point C) {
    return ccw(A, B, C) > 0;
}

bool opposite(Point A, Point B, Point C, Point D) {
    return is_left(A, B, C) != is_left(A, B, D);
}

bool is_between(Point A, Point B, Point C) {
    return min(A.x, B.x) <= C.x && C.x <= max(A.x, B.x) && min(A.y, B.y) <= C.y && C.y <= max(A.y, B.y);
}

bool intersect(Point A, Point B, Point C, Point D) {
    if (isCollinear(A, B, C) && isBetween(A, B, C))
        return true;
    if (isCollinear(A, B, D) && isBetween(A, B, D))
        return true;
    if (isCollinear(C, D, A) && isBetween(C, D, A))
        return true;
    if (isCollinear(C, D, B) && isBetween(C, D, B))
        return true;
    
    return opposite(A, B, C, D) && opposite(C, D, A, B);
}

int main() {
    return 0;
}

/*
    Solution for: UVA 191 - Intersection
    Problem Link: https://onlinejudge.org/external/1/191.pdf
    Verdict: Accepted
    Submission ID: 30153153
    Tags: geometry segment-intersection
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct Point {
        int x, y;
        Point() {}
        Point(int x, int y) : x(x), y(y) {}
        Point operator-(const Point& other) const {
            return Point(x - other.x, y - other.y);
        }
    };
    int sign(int x) { return x ? (x < 0 ? -1 : 1) : 0; }
    int cross(Point p1, Point p2) { return p1.x * p2.y - p1.y * p2.x; }
    int dot(Point p1, Point p2) { return p1.x * p2.x + p1.y * p2.y; }
    int orient(Point p1, Point p2, Point p3) {
        return sign(cross(p2 - p1, p3 - p1));
    }
    bool collinear(Point p1, Point p2, Point p3) {
        return sign(cross(p3 - p1, p3 - p2)) == 0;
    }
    bool between(Point p1, Point p2, Point p3) {
        if (!collinear(p1, p2, p3)) return false;
        return sign(dot(p3 - p1, p3 - p2)) <= 0;
    }
    bool intersect(Point p1, Point p2, Point p3, Point p4) {
        int ori_123 = orient(p1, p2, p3);
        int ori_124 = orient(p1, p2, p4);
        int ori_341 = orient(p3, p4, p1);
        int ori_342 = orient(p3, p4, p2);
        if (ori_123 == 0 && ori_124 == 0) {
            return between(p1, p2, p3) || between(p1, p2, p4) ||
                   between(p3, p4, p1) || between(p3, p4, p2);
        }
        return ori_123 * ori_124 <= 0 && ori_341 * ori_342 <= 0;
    }
    bool inside_rec(int x_min, int x_max, int y_min, int y_max, Point p) {
        return x_min <= p.x && p.x <= x_max && y_min <= p.y && p.y <= y_max;
    }

   public:
    void solve() {
        int num_cases;
        cin >> num_cases;
        while (num_cases--) {
            Point p1, p2;
            int x_min, x_max, y_min, y_max;
            cin >> p1.x >> p1.y >> p2.x >> p2.y;
            cin >> x_min >> y_min >> x_max >> y_max;
            if (x_min > x_max) swap(x_min, x_max);
            if (y_min > y_max) swap(y_min, y_max);
            vector<Point> rec({
                {x_min, y_min},
                {x_max, y_min},
                {x_max, y_max},
                {x_min, y_max},
            });
            cout << "FT"[inside_rec(x_min, x_max, y_min, y_max, p1) ||
                         inside_rec(x_min, x_max, y_min, y_max, p2) ||
                         intersect(rec[0], rec[1], p1, p2) ||
                         intersect(rec[1], rec[2], p1, p2) ||
                         intersect(rec[2], rec[3], p1, p2) ||
                         intersect(rec[3], rec[0], p1, p2)]
                 << '\n';
        }
    }
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
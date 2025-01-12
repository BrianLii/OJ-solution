/*
    Solution for: UVA 11494 - Queen
    Problem Link: https://onlinejudge.org/external/114/11494.pdf
    Verdict: Accepted
    Submission ID: 30096283
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        int x1, x2, y1, y2;
        while (cin >> x1 >> y1 >> x2 >> y2) {
            if (!x1) {
                break;
            } else if (x1 == x2 && y1 == y2) {
                cout << "0\n";
            } else if (x1 == x2 || y1 == y2 || x1 + y1 == x2 + y2 ||
                       x1 - y1 == x2 - y2) {
                cout << "1\n";
            } else {
                cout << "2\n";
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
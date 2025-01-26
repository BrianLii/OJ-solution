/*
    Solution for: UVA 11854 - Egypt
    Problem Link: https://onlinejudge.org/external/118/11854.pdf
    Verdict: Accepted
    Submission ID: 30116886
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        int edge1, edge2, edge3;
        while (cin >> edge1 >> edge2 >> edge3) {
            if (!edge1) return;
            if (edge1 > edge2) swap(edge1, edge2);
            if (edge2 > edge3) swap(edge2, edge3);
            if (edge1 * edge1 + edge2 * edge2 == edge3 * edge3) {
                cout << "right\n";
            } else {
                cout << "wrong\n";
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
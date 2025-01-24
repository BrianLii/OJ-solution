/*
    Solution for: UVA 12372 - Packing for Holiday
    Problem Link: https://onlinejudge.org/external/123/12372.pdf
    Verdict: Accepted
    Submission ID: 30114007
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        int num_cases;
        cin >> num_cases;
        for (int i = 1; i <= num_cases; i++) {
            int L, W, H;
            cin >> L >> W >> H;
            cout << "Case " << i;
            if (L <= 20 && W <= 20 && H <= 20) {
                cout << ": good\n";
            } else {
                cout << ": bad\n";
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
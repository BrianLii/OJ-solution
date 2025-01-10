/*
    Solution for: UVA 900 - Brick Wall Patterns
    Problem Link: https://onlinejudge.org/external/9/900.pdf
    Verdict: Accepted
    Submission ID: 30092317
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        int dp[51] = {1, 1};
        for (int i = 2; i <= 50; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        int num;
        while (cin >> num && num) {
            cout << dp[num] << '\n';
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
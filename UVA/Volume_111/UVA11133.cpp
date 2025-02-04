/*
    Solution for: UVA 11133 - Eigensequence
    Problem Link: https://onlinejudge.org/external/111/11133.pdf
    Verdict: Accepted
    Submission ID: 30131115
    Tags: dp
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        int dp[45];
        int a_1, a_n;
        while (cin >> a_1 >> a_n && (a_1 || a_n)) {
            dp[a_1] = 1;
            for (int i = a_1 + 1; i <= a_n; i++) {
                dp[i] = 0;
                for (int j = a_1; j < i; j++) {
                    if (j % (i - j) == 0) {
                        dp[i] += dp[j];
                    }
                }
            }
            cout << a_1 << ' ' << a_n << ' ' << dp[a_n] << '\n';
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
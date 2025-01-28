/*
    Solution for: UVA 10405 - Longest Common Subsequence
    Problem Link: https://onlinejudge.org/external/104/10405.pdf
    Verdict: Accepted
    Submission ID: 30119197
    Tags: dp lcs
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        string str1, str2;
        static int dp[1001][1001] = {0};
        while (getline(cin, str1)) {
            getline(cin, str2);
            dp[0][0] = 0;
            for (int i = 1; i <= str1.size(); i++) {
                for (int j = 1; j <= str2.size(); j++) {
                    if (str1[i - 1] == str2[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    } else {
                        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                    }
                }
            }
            cout << dp[str1.size()][str2.size()] << '\n';
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
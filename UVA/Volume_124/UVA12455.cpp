/*
    Solution for: UVA 12455 - Bars
    Problem Link: https://onlinejudge.org/external/124/12455.pdf
    Verdict: Accepted
    Submission ID: 30114203
    Tags: dp knapsack
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        int num_cases, num_bars, target;
        int dp[1001];
        cin >> num_cases;
        while (num_cases--) {
            cin >> target >> num_bars;
            dp[0] = true;
            fill(dp + 1, dp + target + 1, false);
            for (int i = 0, bar; i < num_bars; i++) {
                cin >> bar;
                for (int j = target - bar; j >= 0; j--) {
                    if (dp[j]) dp[j + bar] = true;
                }
            }
            if (dp[target]) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
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
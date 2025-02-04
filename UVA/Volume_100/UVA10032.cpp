/*
    Solution for: UVA 10032 - Tug of War
    Problem Link: https://onlinejudge.org/external/100/10032.pdf
    Verdict: Accepted
    Submission ID: 30130417
    Tags: dp knapsack bitmask
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        int num_cases, num_people, weights[100];
        uint64_t dp[450 * 50 + 1];
        cin >> num_cases;
        while (num_cases--) {
            cin >> num_people;
            int sum = 0;
            for (int i = 0; i < num_people; i++) {
                cin >> weights[i];
                sum += weights[i];
            }
            dp[0] = 1;
            fill(dp + 1, dp + sum / 2 + 1, 0);
            for (int i = 0; i < num_people; i++) {
                for (int j = sum / 2; j >= weights[i]; j--) {
                    dp[j] |= dp[j - weights[i]] << 1;
                }
            }
            uint64_t mask = 1LL << (num_people / 2);
            if (num_people % 2) mask |= 1LL << (num_people / 2 + 1);
            for (int i = sum / 2; i >= 0; i--) {
                if (dp[i] & mask) {
                    cout << i << ' ' << sum - i << '\n';
                    break;
                }
            }
            if (num_cases) cout << '\n';
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
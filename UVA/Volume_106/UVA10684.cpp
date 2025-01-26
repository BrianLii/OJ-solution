/*
    Solution for: UVA 10684 - The jackpot
    Problem Link: https://onlinejudge.org/external/106/10684.pdf
    Verdict: Accepted
    Submission ID: 30116929
    Tags: dp max-subarray
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        int num_bets;
        while (cin >> num_bets && num_bets) {
            int max_sum = 0, max_tail = 0;
            for (int i = 0, bet; i < num_bets; i++) {
                cin >> bet;
                max_tail = max(max_tail + bet, bet);
                max_sum = max(max_sum, max_tail);
            }
            if (max_sum) {
                cout << "The maximum winning streak is " << max_sum << ".\n";
            } else {
                cout << "Losing streak.\n";
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
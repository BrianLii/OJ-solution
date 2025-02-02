/*
    Solution for: UVA 10812 - Beat the Spread!
    Problem Link: https://onlinejudge.org/external/108/10812.pdf
    Verdict: Accepted
    Submission ID: 30127390
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        int sum, diff, num_cases;
        cin >> num_cases;
        while (num_cases--) {
            cin >> sum >> diff;
            if ((sum + diff) % 2 == 1 || sum < diff) {
                cout << "impossible\n";
            } else {
                cout << (sum + diff) / 2 << ' ' << (sum - diff) / 2 << '\n';
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
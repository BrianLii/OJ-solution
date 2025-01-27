/*
    Solution for: UVA 10714 - Ants
    Problem Link: https://onlinejudge.org/external/107/10714.pdf
    Verdict: Accepted
    Submission ID: 30117988
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        int num_cases;
        cin >> num_cases;
        while (num_cases--) {
            int length, num_ants;
            cin >> length >> num_ants;
            int max_time = 0, min_time = 0;
            for (int i = 0, position; i < num_ants; i++) {
                cin >> position;
                max_time = max(max_time, max(position, length - position));
                min_time = max(min_time, min(position, length - position));
            }
            cout << min_time << ' ' << max_time << '\n';
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
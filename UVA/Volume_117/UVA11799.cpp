/*
    Solution for: UVA 11799 - Horror Dash
    Problem Link: https://onlinejudge.org/external/117/11799.pdf
    Verdict: Accepted
    Submission ID: 30116891
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        int num_cases;
        cin >> num_cases;
        for (int case_id = 1; case_id <= num_cases; case_id++) {
            int num_speeds, max_speed = 0;
            cin >> num_speeds;
            for (int i = 0, speed; i < num_speeds; i++) {
                cin >> speed;
                max_speed = max(max_speed, speed);
            }
            cout << "Case " << case_id << ": " << max_speed << "\n";
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
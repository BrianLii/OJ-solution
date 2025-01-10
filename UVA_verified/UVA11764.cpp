/*
    Solution for: UVA 11764 - Jumping Mario
    Problem Link: https://onlinejudge.org/external/117/11764.pdf
    Verdict: Accepted
    Submission ID: 30092131
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        int case_num;
        cin >> case_num;
        for (int case_id = 1; case_id <= case_num; case_id++) {
            int wall_num, prev_wall, curr_wall, high = 0, low = 0;
            cin >> wall_num >> prev_wall;
            for (int i = 1; i < wall_num; i++) {
                cin >> curr_wall;
                high += prev_wall < curr_wall;
                low += prev_wall > curr_wall;
                prev_wall = curr_wall;
            }
            cout << "Case " << case_id << ": ";
            cout << high << ' ' << low << '\n';
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
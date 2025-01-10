/*
    Solution for: UVA 11875 - Brick Game
    Problem Link: https://onlinejudge.org/external/118/11875.pdf
    Verdict: Accepted
    Submission ID: 30092301
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        int case_num;
        cin >> case_num;
        for (int i = 1; i <= case_num; i++) {
            int num_team;
            cin >> num_team;
            cout << "Case " << i << ": ";
            for (int i = 0, age; i < num_team; i++) {
                cin >> age;
                if (i == num_team / 2) cout << age << '\n';
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
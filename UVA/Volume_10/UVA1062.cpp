/*
    Solution for: UVA 1062 - Containers
    Problem Link: https://onlinejudge.org/external/10/1062.pdf
    Verdict: Accepted
    Submission ID: 30153322
    Tags: dp lis
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        string ships;
        int case_id = 0;
        char lis[26] = {0};
        while (cin >> ships && ships != "end") {
            int lis_len = 1;
            lis[0] = ships[0];
            for (int i = 1; i < ships.size(); i++) {
                if (ships[i] > lis[lis_len - 1]) {
                    lis[lis_len++] = ships[i];
                } else {
                    *lower_bound(lis, lis + lis_len, ships[i]) = ships[i];
                }
            }
            cout << "Case " << ++case_id << ": ";
            cout << lis_len << "\n";
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
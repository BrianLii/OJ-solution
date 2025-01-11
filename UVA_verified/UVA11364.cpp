/*
    Solution for: UVA 11364 - Optimal Parking
    Problem Link: https://onlinejudge.org/external/113/11364.pdf
    Verdict: Accepted
    Submission ID: 30093149
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        int case_num;
        cin >> case_num;
        while (case_num--) {
            int n, ord, max_ord = -1, min_ord = 100;
            cin >> n;
            for (int i = 0; i < n; i++) {
                cin >> ord;
                max_ord = max(max_ord, ord);
                min_ord = min(min_ord, ord);
            }
            cout << (max_ord - min_ord) * 2 << '\n';
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}

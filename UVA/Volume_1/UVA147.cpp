/*
    Solution for: UVA 147 - Dollars
    Problem Link: https://onlinejudge.org/external/1/147.pdf
    Verdict: Accepted
    Submission ID: 30155531
    Tags: dp change-making
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        int faces[11]{
            2000, 1000, 400, 200, 100, 40, 20, 10, 4, 2, 1,
        };  // unit: 5c
        int64_t ways[6001] = {1};
        for (int i = 0; i < 11; i++) {
            for (int j = faces[i]; j <= 6000; j++) {
                ways[j] += ways[j - faces[i]];
            }
        }
        double query;
        cout << fixed << setprecision(2);
        while (cin >> query) {
            if (query == 0.) break;
            cout << setw(6) << query;
            cout << setw(17) << ways[(int)round(query * 20)] << '\n';
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
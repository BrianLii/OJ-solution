/*
    Solution for: UVA 10127 - Ones
    Problem Link: https://onlinejudge.org/external/101/10127.pdf
    Verdict: Accepted
    Submission ID: 30093369
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        int input;
        while (cin >> input) {
            int current_sum = 0;
            for (int i = 1;; i++) {
                current_sum = (current_sum * 10 + 1) % input;
                if (current_sum == 0) {
                    cout << i << "\n";
                    break;
                }
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
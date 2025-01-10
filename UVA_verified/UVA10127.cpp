/*
    Solution for: 10127 - Ones
    Problem Link: https://onlinejudge.org/external/101/10127.pdf
    Verdict: Accepted
    Submission ID: 30092247
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        int x;
        while (cin >> x) {
            int curr = 1;
            for (int i = 1, curr_sum = 1;;
                 i++, curr_sum = (curr_sum * 10 + 1) % x) {
                if (curr_sum == 0) {
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
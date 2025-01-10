/*
    Solution for: UVA 10929 - You can say 11
    Problem Link: https://onlinejudge.org/external/109/10929.pdf
    Verdict: Accepted
    Submission ID: 30092234
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        string N;
        while (cin >> N && N != "0") {
            int digit_sum = 0;
            for (int i = 0; i < N.size(); i++) {
                if (i & 1) digit_sum += N[i] - '0';
                else digit_sum -= N[i] - '0';
            }
            if (digit_sum % 11) {
                cout << N << " is not a multiple of 11.\n";
            } else {
                cout << N << " is a multiple of 11.\n";
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
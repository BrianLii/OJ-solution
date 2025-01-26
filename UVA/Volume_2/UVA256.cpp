/*
    Solution for: UVA 256 - Quirksome Squares
    Problem Link: https://onlinejudge.org/external/2/256.pdf
    Verdict: Accepted
    Submission ID: 30116857
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int square(int x) { return x * x; }

   public:
    void solve() {
        int pow_10[9] = {1};
        for (int i = 1; i <= 8; i++) {
            pow_10[i] = pow_10[i - 1] * 10;
        }
        int num_digits;
        while (cin >> num_digits) {
            for (int i = 0; i * i < pow_10[num_digits]; i++) {
                if (square(i * i / pow_10[num_digits / 2] +
                           i * i % pow_10[num_digits / 2]) == i * i) {
                    cout << setfill('0') << setw(num_digits) << i * i << '\n';
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
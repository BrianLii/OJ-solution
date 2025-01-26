/*
    Solution for: UVA 374 - Big Mod
    Problem Link: https://onlinejudge.org/external/3/374.pdf
    Verdict: Accepted
    Submission ID: 30116944
    Tags: square-and-mul
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        int base, exponent, mod;
        while (cin >> base >> exponent >> mod) {
            int answer = 1 % mod;
            while (exponent) {
                if (exponent & 1) {
                    answer = (long long)answer * base % mod;
                }
                exponent >>= 1;
                base = (long long)base * base % mod;
            }
            cout << answer << '\n';
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
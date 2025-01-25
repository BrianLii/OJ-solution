/*
    Solution for: UVA 202 - Repeating Decimals
    Problem Link: https://onlinejudge.org/external/2/202.pdf
    Verdict: Accepted
    Submission ID: 30114736
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int appear[3000];

   public:
    void solve() {
        int divident, divisor;
        while (cin >> divident >> divisor) {
            cout << divident << '/' << divisor << " = ";
            cout << divident / divisor;
            divident %= divisor;
            fill(appear, appear + divisor, 0);
            string expansion = ".";
            for (int i = 1;; i++) {
                if (appear[divident]) break;
                appear[divident] = i;
                expansion += divident * 10 / divisor + '0';
                divident = divident * 10 % divisor;
            }
            for (int i = 0; i < expansion.size() && i <= 51; i++) {
                if (i == appear[divident]) cout << '(';
                if (i == 51)
                    cout << "...";
                else
                    cout << expansion[i];
            }
            cout << ")\n   " << expansion.size() - appear[divident];
            cout << " = number of digits in repeating cycle\n\n";
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
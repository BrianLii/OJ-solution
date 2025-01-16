/*
    Solution for: UVA 10931 - Parity
    Problem Link: https://onlinejudge.org/external/109/10931.pdf
    Verdict: Accepted
    Submission ID: 30097649
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        int input;
        while (cin >> input && input) {
            int parity = 0;
            cout << "The parity of ";
            for (int i = 31, start = 0; i >= 0; i--) {
                parity += input >> i & 1;
                start |= parity;
                if (start) cout << (input >> i & 1);
            }
            cout << " is " << parity << " (mod 2).\n";
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
/*
    Solution for: UVA 10469 To Carry or not to Carry
    Problem Link: https://onlinejudge.org/external/104/10469.pdf
    Verdict: Accepted
    Submission ID: 30093159
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        unsigned int num1, num2;
        while (cin >> num1 >> num2) {
            cout << (num1 ^ num2) << '\n';
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
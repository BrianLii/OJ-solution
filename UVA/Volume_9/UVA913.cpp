/*
    Solution for: UVA 913 - Joana and the Odd Numbers
    Problem Link: https://onlinejudge.org/external/9/913.pdf
    Verdict: Accepted
    Submission ID: 30127418
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        int N;
        while (cin >> N) {
            cout << (1LL + N) * (1LL + N) / 2 * 3 - 9 << "\n";
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
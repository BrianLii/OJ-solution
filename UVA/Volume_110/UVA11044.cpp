/*
    Solution for: UVA 11044 - Searching for Nessy
    Problem Link: https://onlinejudge.org/external/110/11044.pdf
    Verdict: Accepted
    Submission ID: 30116841
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        int num_cases, n, m;
        cin >> num_cases;
        while (num_cases--) {
            cin >> n >> m;
            n -= 2;
            m -= 2;
            cout << (n / 3 + bool(n % 3)) * (m / 3 + bool(m % 3)) << '\n';
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
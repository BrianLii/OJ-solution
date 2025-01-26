/*
    Solution for: UVA 11727 - Cost Cutting
    Problem Link: https://onlinejudge.org/external/117/11727.pdf
    Verdict: Accepted
    Submission ID: 30116839
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        int num_cases;
        cin >> num_cases;
        for (int i = 1; i <= num_cases; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            cout << "Case " << i << ": ";
            cout << a + b + c - max({a, b, c}) - min({a, b, c}) << '\n';
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
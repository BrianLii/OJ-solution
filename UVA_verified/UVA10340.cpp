/*
    Solution for: UVA 10340 - All in All
    Problem Link: https://onlinejudge.org/external/103/10340.pdf
    Verdict: Accepted
    Submission ID: 30092166
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        string s, t;
        while (cin >> s >> t) {
            int matched = 0;
            for (int i = 0; i < t.size() && matched < s.size(); i++) {
                if (t[i] == s[matched]) matched++;
            }
            if (matched == s.size()) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
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
/*
    Solution for: UVA 11388 - GCD LCM
    Problem Link: https://onlinejudge.org/external/113/11388.pdf
    Verdict: Accepted
    Submission ID: 30097666
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        int num_cases;
        cin >> num_cases;
        while (num_cases--) {
            int g, l;
            cin >> g >> l;
            if (l % g)
                cout << "-1\n";
            else
                cout << g << ' ' << l << "\n";
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
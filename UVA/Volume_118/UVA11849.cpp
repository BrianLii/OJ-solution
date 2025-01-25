/*
    Solution for: UVA 11849 - CD
    Problem Link: https://onlinejudge.org/external/118/11849.pdf
    Verdict: Accepted
    Submission ID: 30092277
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        int n, m;
        vector<int> jack, jill;
        while (cin >> n >> m && n && m) {
            int ans = 0;
            jack.resize(n);
            jill.resize(m);
            for (int i = 0; i < n; i++) cin >> jack[i];
            for (int i = 0; i < m; i++) cin >> jill[i];
            sort(jack.begin(), jack.end());
            sort(jill.begin(), jill.end());
            for (int i = 0, jill_id = 0; i < n; i++) {
                while (jill_id < m && jill[jill_id] < jack[i]) jill_id++;
                if (jill_id < m && jill[jill_id] == jack[i]) ans++, jill_id++;
            }
            cout << ans << '\n';
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
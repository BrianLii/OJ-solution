/*
    Solution for: UVA 12455 - Bars
    Problem Link: https://onlinejudge.org/external/124/12455.pdf
    Verdict: Accepted
    Submission ID: 30114203
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool dfs(int bars[], int remain, int current) {
        if (!remain) return true;
        if (current == -1) return false;
        if (remain < bars[current]) return false;
        return dfs(bars, remain - bars[current], current - 1) ||
               dfs(bars, remain, current - 1);
    }

   public:
    void solve() {
        int bars[1001];
        int num_cases;
        cin >> num_cases;
        while (num_cases--) {
            int num_bars, target;
            cin >> target >> num_bars;
            for (int i = 0; i < num_bars; i++) {
                cin >> bars[i];
            }
            sort(bars, bars + num_bars, greater<int>());
            if (dfs(bars, target, num_bars - 1)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
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
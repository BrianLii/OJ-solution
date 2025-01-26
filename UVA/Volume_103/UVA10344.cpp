/*
    Solution for: UVA 10344 - 23 out of 5
    Problem Link: https://onlinejudge.org/external/103/10344.pdf
    Verdict: Accepted
    Submission ID: 30116702
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool dfs(int a[5], int pi[5], int current, int eval) {
        if (current == 5) return eval == 23;
        if (dfs(a, pi, current + 1, eval + a[pi[current]])) return true;
        if (dfs(a, pi, current + 1, eval - a[pi[current]])) return true;
        if (dfs(a, pi, current + 1, eval * a[pi[current]])) return true;
        return false;
    }

   public:
    void solve() {
        int a[5], pi[5];
        while (true) {
            for (int i = 0; i < 5; i++) {
                cin >> a[i];
            }
            if (!a[0]) return;
            iota(pi, pi + 5, 0);
            bool success = false;
            do {
                success = success || dfs(a, pi, 1, a[pi[0]]);
            } while (!success && next_permutation(pi, pi + 5));
            if (!success) {
                cout << "Impossible\n";
            } else {
                cout << "Possible\n";
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
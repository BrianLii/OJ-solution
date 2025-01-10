/*
    Solution for: UVA 11417 - GCD
    Problem Link: https://onlinejudge.org/external/114/11417.pdf
    Verdict: Accepted
    Submission ID: 30092204
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        int N;
        int G[501][501] = {0};
        for (int i = 1; i <= 500; i++) {
            for (int j = 1; j <= 500; j++) {
                G[i][j] = G[i - 1][j] - G[i - 1][j - 1] + G[i][j - 1];
                if (i < j) G[i][j] += __gcd(i, j);
            }
        }
        while (cin >> N && N) {
            cout << G[N][N] << '\n';
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
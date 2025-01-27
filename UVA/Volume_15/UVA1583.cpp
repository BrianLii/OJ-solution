/*
    Solution for: UVA 1583 - Digit Generator
    Problem Link: https://onlinejudge.org/external/15/1583.pdf
    Verdict: Accepted
    Submission ID: 30117983
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int digit_sum(int x) {
        int sum = 0;
        while (x) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }

   public:
    void solve() {
        const int max_N = 100000;
        static int memo[100001] = {0};
        for (int i = 1; i < max_N; i++) {
            int generate = digit_sum(i) + i;
            if (generate <= max_N && !memo[generate]) {
                memo[generate] = i;
            }
        }
        int num_cases, N;
        cin >> num_cases;
        while (num_cases--) {
            cin >> N;
            cout << memo[N] << '\n';
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
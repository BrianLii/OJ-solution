/*
    Solution for: UVA 106 - Fermat vs. Pythagoras
    Problem Link: https://onlinejudge.org/external/1/106.pdf
    Verdict: Accepted
    Submission ID: 30116957
    Tags: math difference-array
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        int N;
        const int max_N = 1000000;
        static int used[1000001] = {0};
        static int py_counts[1000001] = {0};
        static int p_counts[1000001] = {0};
        fill(used, used + max_N + 1, INT_MAX);
        for (int i = 1; i * i <= max_N; i++) {
            for (int j = i + 1; i * i + j * j <= max_N; j += 2) {
                if (__gcd(i, j) == 1) {
                    int x = j * j - i * i;
                    int y = 2 * i * j;
                    int z = j * j + i * i;
                    py_counts[z]++;
                    for (int k = 1; z * k <= max_N; k++) {
                        used[x * k] = min(used[x * k], z * k);
                        used[y * k] = min(used[y * k], z * k);
                        used[z * k] = min(used[z * k], z * k);
                    }
                }
            }
        }
        for (int i = 2; i <= max_N; i++) {
            py_counts[i] += py_counts[i - 1];
        }
        for (int i = 1; i <= max_N; i++) {
            if (used[i] != INT_MAX) p_counts[used[i]]++;
        }
        for (int i = 1; i <= max_N; i++) {
            p_counts[i] = 1 + p_counts[i - 1] - p_counts[i];
        }
        while (cin >> N) {
            cout << py_counts[N] << ' ' << p_counts[N] << "\n";
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
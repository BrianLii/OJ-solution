/*
    Solution for: UVA - 524 Prime Ring Problem
    Problem Link: https://onlinejudge.org/external/5/524.pdf
    Verdict: Accepted
    Submission ID: 30098521
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool is_prime[32] = {0};
    vector<int> primes = vector<int>({2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31});

    int nodes[17] = {1};
    void dfs(int used, int depth, int num_nodes) {
        if (depth == num_nodes) {
            if (is_prime[nodes[num_nodes - 1] + 1]) {
                for (int i = 0; i < num_nodes; i++) {
                    if (i) cout << ' ';
                    cout << nodes[i];
                }
                cout << '\n';
            }
            return;
        }
        for (int i = 2; i <= num_nodes; i++) {
            if (!(used >> i & 1) && is_prime[nodes[depth - 1] + i]) {
                nodes[depth] = i;
                dfs(used ^ (1 << i), depth + 1, num_nodes);
            }
        }
    }

   public:
    void solve() {
        for (int prime : primes) is_prime[prime] = true;

        int num_nodes;
        for (int case_id = 1; cin >> num_nodes; case_id++) {
            if (case_id > 1) cout << "\n";
            cout << "Case " << case_id << ":\n";
            dfs(1 << 1, 1, num_nodes);
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
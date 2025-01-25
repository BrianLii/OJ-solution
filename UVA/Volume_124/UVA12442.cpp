/*
    Solution for: UVA 12442 - Forwarding Emails
    Problem Link: https://onlinejudge.org/external/124/12442.pdf
    Verdict: Accepted
    Submission ID: 30114171
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    void build_loop_sizes(int to[], int loop_sizes[], int start) {
        int slow = start, fast = start, loop_size = 0;
        do {
            if (loop_sizes[slow]) return;
            loop_sizes[slow] = -1;
            slow = to[slow];
            fast = to[to[fast]];
        } while (slow != fast);
        do {
            slow = to[slow];
            loop_size++;
        } while (slow != fast);
        do {
            slow = to[slow];
            loop_sizes[slow] = loop_size;
        } while (slow != fast);
    }
    int connected(int to[], int loop_sizes[], int memo[], int current) {
        if (~loop_sizes[current]) return loop_sizes[current];
        if (memo[current]) return memo[current];
        return memo[current] = 1 + connected(to, loop_sizes, memo, to[current]);
    }

   public:
    void solve() {
        const int max_nodes = 50000;
        int to[max_nodes + 1], loop_sizes[max_nodes + 1];
        int memo[max_nodes + 1];
        int num_cases;
        cin >> num_cases;
        for (int case_id = 1; case_id <= num_cases; case_id++) {
            int from, num_nodes;
            cin >> num_nodes;
            for (int i = 1; i <= num_nodes; i++) {
                memo[i] = 0;
                cin >> from >> to[from];
            }
            for (int i = 1; i <= num_nodes; i++) {
                loop_sizes[i] = 0;
                memo[i] = 0;
            }
            for (int i = 1; i <= num_nodes; i++) {
                build_loop_sizes(to, loop_sizes, i);
            }
            int max_size = 0, max_start = 0;
            for (int i = 1; i <= num_nodes; i++) {
                int size = connected(to, loop_sizes, memo, i);
                if (size > max_size) {
                    max_size = size;
                    max_start = i;
                }
            }
            cout << "Case " << case_id << ": ";
            cout << max_start << endl;
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
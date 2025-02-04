/*
    Solution for: UVA 10086 - Test the Rods
    Problem Link: https://onlinejudge.org/external/100/10086.pdf
    Verdict: Accepted
    Submission ID: 30130306
    Tags: dp backtracking
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    void solve_one(int T1, int T2) {
        int num_sites, site_rod;
        static int num_rods[31];
        static int cost_1[31][301], cost_2[31][301];
        static int min_cost[31][301], min_from[31][301];
        static int path[31];
        cin >> num_sites;
        for (int i = 1; i <= num_sites; i++) {
            cin >> num_rods[i];
            for (int j = 1; j <= num_rods[i]; j++) {
                cin >> cost_1[i][j];
            }
            for (int j = 1; j <= num_rods[i]; j++) {
                cin >> cost_2[i][j];
            }
        }
        min_cost[0][0] = 0;
        fill(min_cost[0] + 1, min_cost[0] + T1 + 1, 1e6);
        for (int i = 1; i <= num_sites; i++) {
            for (int j = 0; j <= T1; j++) {
                min_cost[i][j] = 1e6;
                for (int k = 0; k <= num_rods[i] && k <= j; k++) {
                    int curr_cost = min_cost[i - 1][j - k] + cost_1[i][k] +
                                    cost_2[i][num_rods[i] - k];
                    if (curr_cost < min_cost[i][j]) {
                        min_cost[i][j] = curr_cost;
                        min_from[i][j] = j - k;
                    }
                }
            }
        }
        cout << min_cost[num_sites][T1] << '\n';
        for (int i = num_sites, curr_state = T1; i >= 1; i--) {
            path[i] = curr_state - min_from[i][curr_state];
            curr_state = min_from[i][curr_state];
        }
        cout << path[1];
        for (int i = 2; i <= num_sites; i++) {
            cout << ' ' << path[i];
        }
        cout << "\n\n";
    }

   public:
    void solve() {
        int T1, T2;
        while (cin >> T1 >> T2 && T1 + T2) solve_one(T1, T2);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
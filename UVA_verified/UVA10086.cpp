/*
    Solution for: UVA 10086 Test the Rods
    Problem Link: https://onlinejudge.org/external/100/10086.pdf
    Verdict: Accepted
    Submission ID: 30093486
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    void solve_one(int T1, int T2) {
        int site_num, site_rod;
        cin >> site_num;
        vector<int> rod_num(site_num + 1);
        vector<vector<int>> cost_1(site_num + 1), cost_2(site_num + 1);
        for (int i = 1; i <= site_num; i++) {
            cin >> rod_num[i];
            cost_1[i].resize(rod_num[i] + 1);
            for (int j = 1; j <= rod_num[i]; j++) {
                cin >> cost_1[i][j];
            }
            cost_2[i].resize(rod_num[i] + 1);
            for (int j = 1; j <= rod_num[i]; j++) {
                cin >> cost_2[i][j];
            }
        }
        vector<vector<int>> min_cost(site_num + 1, vector<int>(T1 + 1, 1e6));
        vector<vector<int>> min_from(site_num + 1, vector<int>(T1 + 1, 1e6));
        min_cost[0][0] = 0;
        for (int i = 1; i <= site_num; i++) {
            for (int j = 0; j <= T1; j++) {
                for (int k = 0; k <= rod_num[i] && k <= j; k++) {
                    int curr_cost = min_cost[i - 1][j - k] + cost_1[i][k] +
                                    cost_2[i][rod_num[i] - k];
                    if (curr_cost < min_cost[i][j]) {
                        min_cost[i][j] = curr_cost;
                        min_from[i][j] = j - k;
                    }
                }
            }
        }
        cout << min_cost[site_num][T1] << '\n';
        vector<int> path(site_num + 1);
        for (int i = site_num, curr_state = T1; i >= 1; i--) {
            path[i] = curr_state - min_from[i][curr_state];
            curr_state = min_from[i][curr_state];
        }
        cout << path[1];
        for (int i = 2; i <= site_num; i++) cout << ' ' << path[i];
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
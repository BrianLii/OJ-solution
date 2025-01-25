/*
    Solution for: UVA 10074 - Take the Land
    Problem Link: https://onlinejudge.org/external/100/10074.pdf
    Verdict: Accepted
    Submission ID: 30095399
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    const int max_num_rows = 100, max_num_cols = 100;
    vector<vector<int>> tree_map =
        vector<vector<int>>(max_num_rows + 1, vector<int>(max_num_cols + 1));

   public:
    void solve(int num_rows, int num_cols) {
        for (int i = 1; i <= num_rows; i++) {
            for (int j = 1; j <= num_cols; j++) {
                cin >> tree_map[i][j];
                tree_map[i][j] += tree_map[i - 1][j] - tree_map[i - 1][j - 1] +
                                  tree_map[i][j - 1];
            }
        }
        int max_area = 0;
        for (int top = 1; top <= num_rows; top++) {
            for (int bot = 1; bot <= num_rows; bot++) {
                int max_width = 0;
                for (int col = 1; col <= num_cols; col++) {
                    int col_sum = tree_map[bot][col] - tree_map[top - 1][col] -
                                  tree_map[bot][col - 1] +
                                  tree_map[top - 1][col - 1];
                    if (col_sum == 0) {
                        max_area =
                            max(max_area, (bot - top + 1) * (++max_width));
                    } else {
                        max_width = 0;
                    }
                }
            }
        }
        cout << max_area << '\n';
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int num_rows, num_cols;
    while (cin >> num_rows >> num_cols && num_rows)
        Solution().solve(num_rows, num_cols);
    return 0;
}
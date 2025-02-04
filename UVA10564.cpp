/*
    Solution for: UVA 10564 - Paths through the Hourglass
    Problem Link: https://onlinejudge.org/external/105/10564.pdf
    Verdict: Accepted
    Submission ID: 30127567
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int values[40][20];
    long long num_path[40][20][500];

   public:
    void solve() {
        int width, target;
        while (cin >> width >> target && width) {
            for (int i = 0; i < width; i++) {
                for (int j = 0; j < width - i; j++) {
                    cin >> values[i][j];
                    fill(num_path[i][j], num_path[i][j] + target + 1, 0);
                }
            }
            for (int i = width; i < width * 2 - 1; i++) {
                for (int j = 0; j < i - width + 2; j++) {
                    cin >> values[i][j];
                    fill(num_path[i][j], num_path[i][j] + target + 1, 0);
                }
            }
            for (int i = width * 2 - 2; i >= width - 1; i--) {
                for (int j = 0; j < i - width + 2; j++) {
                    if (i == width * 2 - 2) {
                        num_path[i][j][values[i][j]] = 1;
                        continue;
                    }
                    for (int k = values[i][j]; k <= target; k++) {
                        num_path[i][j][k] =
                            num_path[i + 1][j][k - values[i][j]] +
                            num_path[i + 1][j + 1][k - values[i][j]];
                    }
                }
            }
            for (int i = width - 2; i >= 0; i--) {
                for (int j = 0; j < width - i; j++) {
                    for (int k = values[i][j]; k <= target; k++) {
                        num_path[i][j][k] = 0;
                        if (j + 1 < width - i) {
                            num_path[i][j][k] =
                                num_path[i + 1][j][k - values[i][j]];
                        }
                        if (j) {
                            num_path[i][j][k] +=
                                num_path[i + 1][j - 1][k - values[i][j]];
                        }
                    }
                }
            }

            long long total = 0;
            int start_col = -1;
            for (int j = 0; j < width; j++) {
                total += num_path[0][j][target];
                if (num_path[0][j][target] && start_col == -1) start_col = j;
            }

            cout << total << '\n';
            if (!total) {
                cout << "\n";
                continue;
            }

            int current_col = start_col, current_sum = target;
            cout << start_col << " ";
            string answer = "";
            for (int i = 0; i < width - 1; i++) {
                current_sum -= values[i][current_col];
                if (current_col &&
                    num_path[i + 1][current_col - 1][current_sum]) {
                    answer += 'L';
                    current_col--;
                } else {
                    answer += 'R';
                }
            }
            for (int i = width - 1; i < width * 2 - 2; i++) {
                current_sum -= values[i][current_col];
                if (num_path[i + 1][current_col][current_sum]) {
                    answer += 'L';
                } else {
                    answer += 'R';
                    current_col++;
                }
            }
            cout << answer << '\n';
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
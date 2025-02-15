/*
    Solution for: UVA 116 - Unidirectional TSP
    Problem Link: https://onlinejudge.org/external/1/116.pdf
    Verdict: Accepted
    Submission ID: 30151095
    Tags: dp
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        int case_id = 0, width, height;
        int min_cost[10][100], min_path[10][100], matrix[10][100];
        while (cin >> height >> width) {
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    cin >> matrix[i][j];
                }
            }
            for (int i = 0; i < height; i++) {
                min_cost[i][width - 1] = matrix[i][width - 1];
            }
            for (int j = width - 2; j >= 0; j--) {
                for (int i = 0; i < height; i++) {
                    int sub, mid, add;
                    if (height == 1) {
                        sub = mid = add = i;
                    } else if (i == 0) {
                        sub = 0;
                        mid = 1;
                        add = height - 1;
                    } else if (i == height - 1) {
                        sub = 0;
                        mid = height - 2;
                        add = height - 1;
                    } else {
                        sub = i - 1;
                        mid = i;
                        add = i + 1;
                    }
                    min_cost[i][j] = min_cost[sub][j + 1];
                    min_path[i][j] = sub;
                    if (min_cost[i][j] > min_cost[mid][j + 1]) {
                        min_cost[i][j] = min_cost[mid][j + 1];
                        min_path[i][j] = mid;
                    }
                    if (min_cost[i][j] > min_cost[add][j + 1]) {
                        min_cost[i][j] = min_cost[add][j + 1];
                        min_path[i][j] = add;
                    }
                    min_cost[i][j] += matrix[i][j];
                }
            }
            int curr_row = 0, curr_col = 0, answer = 0;
            for (int i = 0; i < height; i++) {
                if (min_cost[i][0] < min_cost[curr_row][0]) {
                    curr_row = i;
                }
            }
            answer = min_cost[curr_row][0];
            while (curr_col < width) {
                cout << curr_row + 1;
                if (curr_col == width - 1) {
                    cout << '\n';
                } else {
                    cout << ' ';
                }
                curr_row = min_path[curr_row][curr_col];
                curr_col++;
            }
            cout << answer << "\n";
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
/*
    Solution for: UVA 116 - Unidirectional TSP
    Problem Link: https://onlinejudge.org/external/1/116.pdf
    Verdict: Accepted
    Submission ID: 30151729
    Tags: dp
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        int width, height, matrix[10][100];
        int min_cost[10][100], min_path[10][100];
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
                    int top, mid, bot;
                    if (height == 1) {
                        top = mid = bot = i;
                    } else if (i == 0) {
                        top = 0;
                        mid = 1;
                        bot = height - 1;
                    } else if (i == height - 1) {
                        top = 0;
                        mid = height - 2;
                        bot = height - 1;
                    } else {
                        top = i - 1;
                        mid = i;
                        bot = i + 1;
                    }
                    min_cost[i][j] = min_cost[top][j + 1];
                    min_path[i][j] = top;
                    if (min_cost[i][j] > min_cost[mid][j + 1]) {
                        min_cost[i][j] = min_cost[mid][j + 1];
                        min_path[i][j] = mid;
                    }
                    if (min_cost[i][j] > min_cost[bot][j + 1]) {
                        min_cost[i][j] = min_cost[bot][j + 1];
                        min_path[i][j] = bot;
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
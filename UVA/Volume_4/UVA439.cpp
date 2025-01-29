/*
    Solution for: UVA 439 - Knight Moves
    Problem Link: https://onlinejudge.org/external/4/439.pdf
    Verdict: Accepted
    Submission ID: 30120643
    Tags: bfs
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        const int dx[8] = {-1, -1, 1, 1, -2, -2, 2, 2};
        const int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
        static int depth[8][8];
        string pos_1, pos_2;
        while (cin >> pos_1 >> pos_2) {
            memset(depth, 0, sizeof(depth));
            int x_1, x_2, y_1, y_2;
            x_1 = pos_1[0] - 'a';
            x_2 = pos_2[0] - 'a';
            y_1 = pos_1[1] - '1';
            y_2 = pos_2[1] - '1';
            queue<pair<int, int>> que;
            que.emplace(x_1, y_1);
            depth[x_1][y_1] = 1;
            while (que.size()) {
                int curr_x = que.front().first;
                int curr_y = que.front().second;
                que.pop();
                if (curr_x == x_2 && curr_y == y_2) {
                    break;
                }
                for (int i = 0; i < 8; i++) {
                    int next_x = curr_x + dx[i];
                    int next_y = curr_y + dy[i];
                    if (0 <= next_x && next_x < 8 && 0 <= next_y &&
                        next_y < 8 && !depth[next_x][next_y]) {
                        depth[next_x][next_y] = depth[curr_x][curr_y] + 1;
                        que.emplace(next_x, next_y);
                    }
                }
            }
            cout << "To get from " << pos_1 << " to " << pos_2 << " takes ";
            cout << depth[x_2][y_2] - 1 << " knight moves.\n";
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
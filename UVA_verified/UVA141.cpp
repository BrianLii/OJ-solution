/*
    Solution for: UVA 141 - The Spot Game
    Problem Link: https://onlinejudge.org/external/1/141.pdf
    Verdict: Accepted
    Submission ID: 30112837
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        int board_size;
        vector<long long> current[4];
        while (cin >> board_size && board_size) {
            for (int i = 0; i < 4; i++) {
                current[i].resize(board_size);
                fill(current[i].begin(), current[i].end(), 0);
            }
            int pos_x, pos_y, r_pos_x, r_pos_y;
            string type;
            map<vector<long long>, bool> appear;
            bool playing = true;
            for (int i = 1; i <= board_size * 2; i++) {
                cin >> pos_x >> pos_y >> type;
                if (!playing) continue;
                pos_x--;
                pos_y--;
                r_pos_x = board_size - pos_x - 1;
                r_pos_y = board_size - pos_y - 1;
                current[0][pos_x] ^= 1LL << pos_y;
                current[1][pos_y] ^= 1LL << r_pos_x;
                current[2][r_pos_x] ^= 1LL << r_pos_y;
                current[3][r_pos_y] ^= 1LL << pos_x;

                if (appear[current[0]]) {
                    cout << "Player " << "12"[i % 2] << " wins on move ";
                    cout << i << "\n";
                    playing = false;
                }
                for (int i = 0; i < 4; i++) {
                    appear[current[i]] = true;
                }
            }
            if (playing) {
                cout << "Draw\n";
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
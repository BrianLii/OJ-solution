/*
    Solution for: UVA 541 - Error Correction
    Problem Link: https://onlinejudge.org/external/5/541.pdf
    Verdict: Accepted
    Submission ID: 30113281
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        int size;
        int matrix[100][100];
        while (cin >> size && size) {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    cin >> matrix[i][j];
                }
            }
            int row_id = -1, col_id = -1;
            bool corrupt = false;
            for (int i = 0; i < size; i++) {
                int parity = 0;
                for (int j = 0; j < size; j++) {
                    parity ^= matrix[i][j];
                }
                if (!parity) continue;
                if (row_id != -1) {
                    corrupt = true;
                } else {
                    row_id = i;
                }
            }
            for (int j = 0; j < size; j++) {
                int parity = 0;
                for (int i = 0; i < size; i++) {
                    parity ^= matrix[i][j];
                }
                if (!parity) continue;
                if (col_id != -1) {
                    corrupt = true;
                } else {
                    col_id = j;
                }
            }
            if (corrupt) {
                cout << "Corrupt\n";
            } else if (row_id == -1 && col_id == -1) {
                cout << "OK\n";
            } else {
                cout << "Change bit (";
                cout << row_id + 1 << ',' << col_id + 1 << ")\n";
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
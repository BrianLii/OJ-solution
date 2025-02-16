/*
    Solution for: UVA 11235 - Frequent values
    Problem Link: https://onlinejudge.org/external/112/11235.pdf
    Verdict: Accepted
    Submission ID: 30153308
    Tags: sparse-table
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int sparse_query(int sparse[][20], int low, int high) {
        if (low > high) return 0;
        int block = __lg(high - low + 1);
        return max(sparse[low][block], sparse[high - (1 << block) + 1][block]);
    }

   public:
    void solve() {
        static int sparse[1000001][20];
        static int block[1000001], block_size[1000001], seq[1000001];
        int num_queries, seq_len;
        while (cin >> seq_len >> num_queries) {
            for (int i = 1; i <= seq_len; i++) {
                cin >> seq[i];
                if (i == 1 || seq[i] != seq[i - 1]) {
                    block[i] = i;
                    block_size[i] = 1;
                } else {
                    block[i] = block[i - 1];
                    block_size[block[i]]++;
                }
            }
            for (int i = 1; i <= seq_len; i++) {
                sparse[i][0] = block_size[i] = block_size[block[i]];
            }
            for (int j = 1, lg = __lg(seq_len); j <= lg; j++) {
                for (int i = 1; i <= seq_len; i++) {
                    sparse[i][j] = max({
                        sparse[i][j - 1],
                        sparse[min(seq_len, i + (1 << (j - 1)))][j - 1],
                    });
                }
            }
            int low, high;
            while (num_queries--) {
                cin >> low >> high;
                if (block[low] == block[high]) {
                    cout << high - low + 1 << '\n';
                } else {
                    cout << max({
                        block_size[low] - (low - block[low]),
                        sparse_query(sparse, block[low] + block_size[low],
                                     block[high] - 1),
                        high - block[high] + 1,
                    });
                    cout << '\n';
                }
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
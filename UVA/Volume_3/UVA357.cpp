/*
    Solution for: UVA 357 - Let Me Count The Ways
    Problem Link: https://onlinejudge.org/external/3/357.pdf
    Verdict: Accepted
    Submission ID: 30150943
    Tags: dp coin-changing
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        const int max_num = 30000;
        const int faces[5] = {1, 5, 10, 25, 50};
        int64_t ways[max_num + 1] = {1};
        for (int i = 0; i < 5; i++) {
            for (int j = faces[i]; j <= max_num; j++) {
                ways[j] += ways[j - faces[i]];
            }
        }
        int num;
        while (cin >> num) {
            if (ways[num] == 1) {
                cout << "There is only 1 way ";
            } else {
                cout << "There are " << ways[num] << " ways ";
            }
            cout << "to produce " << num << " cents change.\n";
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
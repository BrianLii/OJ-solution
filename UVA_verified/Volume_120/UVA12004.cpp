/*
    Solution for: UVA 12004 - Bubble Sort
    Problem Link: https://onlinejudge.org/external/120/12004.pdf
    Verdict: Accepted
    Submission ID: 30113789
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        int num_cases;
        cin >> num_cases;
        for (int case_id = 1; case_id <= num_cases; case_id++) {
            long long arr_len, answer;
            cin >> arr_len;
            cout << "Case " << case_id << ": ";
            answer = arr_len * (arr_len - 1) / 2;
            if (answer % 2) {
                cout << answer << "/2\n";
            } else {
                cout << answer / 2 << "\n";
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
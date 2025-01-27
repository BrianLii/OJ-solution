/*
    Solution for: UVA 993 - Product of digits
    Problem Link: https://onlinejudge.org/external/9/993.pdf
    Verdict: Accepted
    Submission ID: 30118084
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        int num_cases;
        cin >> num_cases;
        while (num_cases--) {
            int N;
            cin >> N;
            if (N == 0) {
                cout << "10\n";
                continue;
            }
            if (N == 1) {
                cout << "1\n";
                continue;
            }
            vector<int> answer;
            for (int i = 9; i >= 2; i--) {
                while (N % i == 0) {
                    answer.emplace_back(i);
                    N /= i;
                }
            }
            if (N > 1) {
                cout << "-1\n";
                continue;
            }
            for (int i = answer.size() - 1; i >= 0; i--) {
                cout << answer[i];
            }
            cout << "\n";
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
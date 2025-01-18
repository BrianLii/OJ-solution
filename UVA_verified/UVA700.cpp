/*
    Solution for: UVA 700 - Date Bugs
    Problem Link: https://onlinejudge.org/external/7/700.pdf
    Verdict: Accepted
    Submission ID: 30105628
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        int num_computers, case_id = 0;
        vector<vector<int>> computers;
        while (cin >> num_computers && num_computers) {
            computers.resize(num_computers);
            int start_date = 0;
            for (vector<int> &computer : computers) {
                computer.resize(3);
                cin >> computer[0] >> computer[1] >> computer[2];
                start_date = max(start_date, computer[1]);
            }
            int answer = -1;
            for (int i = start_date; i < 10000; i++) {
                bool fail = false;
                for (vector<int> &computer : computers) {
                    if (computer[1] +
                            (i - computer[1]) % (computer[2] - computer[1]) !=
                        computer[0]) {
                        fail = true;
                    }
                }
                if (!fail) {
                    answer = i;
                    break;
                }
            }
            cout << "Case #" << ++case_id << ":\n";
            if (answer == -1)
                cout << "Unknown bugs detected.\n\n";
            else
                cout << "The actual year is " << answer << ".\n\n";
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
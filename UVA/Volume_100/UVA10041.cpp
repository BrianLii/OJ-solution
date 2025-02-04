/*
    Solution for: UVA 10041 - Vito’s family
    Problem Link: https://onlinejudge.org/external/100/10041.pdf
    Verdict: Accepted
    Submission ID: 30130447
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        int num_cases, num_relatives;
        int relatives[500];
        cin >> num_cases;
        while (num_cases--) {
            int num_relatives;
            cin >> num_relatives;
            for (int i = 0; i < num_relatives; i++) {
                cin >> relatives[i];
            }
            sort(relatives, relatives + num_relatives);
            int answer = 0;
            for (int i = 0; i < num_relatives; i++) {
                answer += abs(relatives[i] - relatives[num_relatives / 2]);
            }
            cout << answer << '\n';
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
/*
    Solution for: UVA 1225 - Digit Counting
    Problem Link: https://onlinejudge.org/external/12/1225.pdf
    Verdict: Accepted
    Submission ID: 30147377
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        int num_cases;
        cin >> num_cases;
        while (num_cases--) {
            int number;
            cin >> number;
            for (int i = 0; i <= 9; i++) {
                int answer = 0, prefix = number, pow_10 = 1, suffix = 0;
                while (prefix > 0) {
                    if (i == 0) {
                        if (i == prefix % 10) {
                            answer += (prefix / 10 - 1) * pow_10 + suffix + 1;
                        } else {
                            answer += (prefix / 10 - 1) * pow_10 + pow_10;
                        }
                    } else if (i < prefix % 10) {
                        answer += prefix / 10 * pow_10 + pow_10;
                    } else if (i == prefix % 10) {
                        answer += prefix / 10 * pow_10 + suffix + 1;
                    } else {
                        answer += prefix / 10 * pow_10;
                    }
                    suffix += prefix % 10 * pow_10;
                    prefix /= 10;
                    pow_10 *= 10;
                }
                if (i) cout << ' ';
                cout << answer;
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
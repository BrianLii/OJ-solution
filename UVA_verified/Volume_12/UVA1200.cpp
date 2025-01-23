/*
    Solution for: UVA 1200 - A DP Problem
    Problem Link: https://onlinejudge.org/external/12/1200.pdf
    Verdict: Accepted
    Submission ID: 30113397
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        int num_cases;
        cin >> num_cases;
        while (num_cases--) {
            string input;
            cin >> input;
            int coef_x = 0, coef_const = 0;
            for (int i = 0, sign = 1, side = 1; i < input.size(); i++) {
                if (input[i] == '+') {
                    sign = 1;
                    continue;
                }
                if (input[i] == '-') {
                    sign = -1;
                    continue;
                }
                if (input[i] == '=') {
                    side = -1;
                    sign = 1;
                    continue;
                }
                if (input[i] == 'x') {
                    coef_x += 1 * sign * side;
                    continue;
                }
                int current_const = 0;
                for (int j = i; j < input.size(); j++) {
                    if (isdigit(input[j])) {
                        current_const = current_const * 10 + input[j] - '0';
                        i = j;
                    } else {
                        break;
                    }
                }
                if (i + 1 < input.size() && input[i + 1] == 'x') {
                    coef_x += current_const * sign * side;
                    i++;
                } else {
                    coef_const += current_const * sign * side;
                }
            }

            if (!coef_x && !coef_const) {
                cout << "IDENTITY\n";
            } else if (!coef_x) {
                cout << "IMPOSSIBLE\n";
            } else {
                if (coef_x < 0) {
                    coef_x = -coef_x;
                    coef_const = -coef_const;
                }
                if (-coef_const < 0) {
                    cout << -coef_const / coef_x - (-coef_const % coef_x != 0);
                } else {
                    cout << -coef_const / coef_x;
                }
                cout << "\n";
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
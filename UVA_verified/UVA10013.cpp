/*
    Solution for: UVA 10013 - Super long sums
    Problem Link: https://onlinejudge.org/external/100/10013.pdf
    Verdict: Accepted
    Submission ID: 30095476
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        int num_cases;
        cin >> num_cases;
        vector<short> result(1000000);
        while (num_cases--) {
            int num_digits;
            short digit_1, digit_2, carry = 0;
            cin >> num_digits;
            for (int i = 0; i < num_digits; i++) {
                cin >> digit_1 >> digit_2;
                result[i] = digit_1 + digit_2;
            }
            for (int i = num_digits - 1; i >= 0; i--) {
                result[i] += carry;
                carry = result[i] >= 10;
                if (carry) result[i] -= 10;
            }
            if (carry) cout << '1';
            for (int i = 0; i < num_digits; i++) {
                cout << result[i];
            }
            cout << '\n';
            if (num_cases) cout << '\n';
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
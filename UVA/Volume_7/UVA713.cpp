/*
    Solution for: UVA 713 - Adding Reversed Numbers
    Problem Link: https://onlinejudge.org/external/7/713.pdf
    Verdict: Accepted
    Submission ID: 30125564
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        int num_cases;
        cin >> num_cases;
        while (num_cases--) {
            string num_1, num_2, result;
            cin >> num_1 >> num_2;
            int carry = 0;
            for (int i = 0; i < num_1.size() || i < num_2.size() || carry;
                 i++) {
                if (i < num_1.size()) carry += num_1[i] - '0';
                if (i < num_2.size()) carry += num_2[i] - '0';
                result.push_back(carry % 10 + '0');
                carry /= 10;
            }
            int start = 0;
            while (result[start] == '0') start++;
            for (int i = start; i < result.size(); i++) {
                cout << result[i];
            }
            cout << '\n';
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
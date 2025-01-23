/*
    Solution for: UVA 424 - Integer Inquiry
    Problem Link: https://onlinejudge.org/external/4/424.pdf
    Verdict: Accepted
    Submission ID:
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        string input[101];
        int input_num = 0;
        while (cin >> input[input_num] && input[input_num] != "0") {
            input_num++;
        }
        int max_len = 0;
        for (int i = 0; i < input_num; i++) {
            reverse(input[i].begin(), input[i].end());
            max_len = max(max_len, (int)input[i].size());
        }
        string result = "";
        for (int i = 0, carry = 0; i < max_len || carry; i++) {
            for (int j = 0; j < input_num; j++) {
                if (i < input[j].size()) carry += input[j][i] - '0';
            }
            result += carry % 10 + '0';
            carry /= 10;
        }
        reverse(result.begin(), result.end());
        if (result.size()) {
            cout << result << "\n";
        } else {
            cout << "0\n";
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
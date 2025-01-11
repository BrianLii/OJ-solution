/*
    Solution for: UVA 10019 - Funny Encryption Method
    Problem Link: https://onlinejudge.org/external/100/10019.pdf
    Verdict: Accepted
    Submission ID: 30093176
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int bit_count(int number) {
        int result = 0;
        while (number) {
            result += number & 1;
            number >>= 1;
        }
        return result;
    }

   public:
    void solve() {
        int test_cases;
        cin >> test_cases;
        while (test_cases--) {
            string input_number;
            cin >> input_number;
            int dec_value = 0, hex_value = 0;
            for (char digit : input_number) {
                dec_value = dec_value * 10 + digit - '0';
                hex_value = hex_value * 16 + digit - '0';
            }
            cout << bit_count(dec_value) << ' ' << bit_count(hex_value) << '\n';
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
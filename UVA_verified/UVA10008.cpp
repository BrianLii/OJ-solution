/*
    Solution for: 10008 What’s Cryptanalysis?
    Problem Link: https://onlinejudge.org/external/100/10008.pdf
    Verdict: Accepted
    Submission ID: 30093393
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        string input;
        int rows;
        cin >> rows;
        getline(cin, input);
        int freq[26] = {0}, index[26];
        while (rows--) {
            getline(cin, input);
            for (char chr : input) {
                if (isalpha(chr)) freq[toupper(chr) - 'A']++;
            }
        }
        iota(index, index + 26, 0);
        stable_sort(index, index + 26, [&freq](const int &lhs, const int &rhs) {
            return freq[lhs] > freq[rhs];
        });
        for (int i = 0; i < 26 && freq[index[i]]; i++) {
            cout << char(index[i] + 'A') << ' ' << freq[index[i]] << '\n';
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
/*
    Solution for: UVA 10222 - Decode the Mad man
    Problem Link: https://onlinejudge.org/external/102/10222.pdf
    Verdict: Accepted
    Submission ID: 30116727
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        const string from = "ertyuiop[]dfghjkl;'cvbnm,.";
        const string to = "qwertyuiopasdfghjklzxcvbnm";
        char table[256] = {0};
        for (int i = 0; i < 26; i++) table[from[i]] = to[i];
        string input;
        while (getline(cin, input)) {
            for (char chr : input) {
                if (!table[chr]) {
                    cout << chr;
                } else {
                    cout << table[chr];
                }
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
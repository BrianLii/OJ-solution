/*
    Solution for: UVA 10922 - 2 the 9s
    Problem Link: https://onlinejudge.org/external/109/10922.pdf
    Verdict: Accepted
    Submission ID: 30092398
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int degree(int n) {
        if (n <= 9) return 0;
        int sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return 1 + degree(sum);
    }

   public:
    void solve() {
        string n;
        while (cin >> n && n != "0") {
            int sum = 0;
            for (int i = 0; i < n.size(); i++) sum += n[i] - '0';
            if (sum % 9) {
                cout << n << " is not a multiple of 9.\n";
            } else {
                cout << n << " is a multiple of 9 and has 9-degree "
                     << 1 + degree(sum) << ".\n";
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
/*
    Solution for: UVA 568 - Just the Facts
    Problem Link: https://onlinejudge.org/external/5/568.pdf
    Verdict: Accepted
    Submission ID: 30092374
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        int last_digit[10001] = {0}, prod_no_2_5 = 1, count_2 = 0, count_5 = 0;
        for (int i = 1; i <= 10000; i++) {
            int x = i;
            while (x % 2 == 0) {
                count_2++;
                x /= 2;
            }
            while (x % 5 == 0) {
                count_5++;
                x /= 5;
            }
            prod_no_2_5 = prod_no_2_5 * x % 10;
            last_digit[i] =
                (prod_no_2_5 << ((count_2 - count_5 - 1) % 4 + 1)) % 10;
        }
        int N;
        while (cin >> N) {
            cout << setw(5) << N;
            cout << " -> " << last_digit[N] << "\n";
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
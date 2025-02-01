/*
    Solution for: UVA 382 - Perfection
    Problem Link: https://onlinejudge.org/external/3/382.pdf
    Verdict: Accepted
    Submission ID: 30125508
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        cout << "PERFECTION OUTPUT\n";
        int number;
        while (cin >> number && number) {
            int sum = 0;
            for (int i = 1; i * i <= number; i++) {
                if (number % i) continue;
                sum += i;
                if (i * i != number) {
                    sum += number / i;
                }
            }
            sum -= number;
            cout << setw(5) << number;
            if (sum == number) {
                cout << "  PERFECT\n";
            } else if (sum < number) {
                cout << "  DEFICIENT\n";
            } else {
                cout << "  ABUNDANT\n";
            }
        }
        cout << "END OF OUTPUT\n";
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
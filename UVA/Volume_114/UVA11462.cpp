/*
    Solution for: UVA 11462 - Age Sort
    Problem Link: https://onlinejudge.org/external/114/11462.pdf
    Verdict: Accepted
    Submission ID: 30116921
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        int num_ages;
        static int ages[2000000];
        while (cin >> num_ages && num_ages) {
            for (int i = 0; i < num_ages; i++) {
                cin >> ages[i];
            }
            sort(ages, ages + num_ages);
            for (int i = 0; i < num_ages; i++) {
                if (i) cout << ' ';
                cout << ages[i];
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
/*
    Solution for: UVA 11462 - Age Sort
    Problem Link: https://onlinejudge.org/external/114/11462.pdf
    Verdict: Accepted
    Submission ID: 30130562
    Tags: counting-sort
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        int num_ages, counts[100];
        while (cin >> num_ages && num_ages) {
            fill(counts, counts + 100, 0);
            for (int i = 0, age; i < num_ages; i++) {
                cin >> age;
                counts[age]++;
            }
            bool is_first = true;
            for (int i = 0; i < 100; i++) {
                for (int j = 0; j < counts[i]; j++) {
                    if (is_first) {
                        is_first = false;
                    } else {
                        cout << ' ';
                    }
                    cout << i;
                }
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
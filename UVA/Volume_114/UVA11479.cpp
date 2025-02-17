/*
    Solution for: UVA 11479 - Is this the easiest problem?
    Problem Link: https://onlinejudge.org/external/114/11479.pdf
    Verdict: Accepted
    Submission ID: 30155565
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        int num_cases;
        int64_t sides[3];
        cin >> num_cases;
        for (int i = 1; i <= num_cases; i++) {
            cin >> sides[0] >> sides[1] >> sides[2];
            sort(sides, sides + 3);
            cout << "Case " << i << ": ";
            if (sides[0] + sides[1] <= sides[2]) {
                cout << "Invalid\n";
            } else if (sides[0] == sides[2]) {
                cout << "Equilateral\n";
            } else if (sides[0] == sides[1] || sides[1] == sides[2]) {
                cout << "Isosceles\n";
            } else {
                cout << "Scalene\n";
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
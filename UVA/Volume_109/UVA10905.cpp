/*
    Solution for: UVA 10905 - Children's Game
    Problem Link: https://onlinejudge.org/external/109/10905.pdf
    Verdict: Accepted
    Submission ID: 30117997
    Tags: sorting
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        int num_inputs;
        string inputs[50];
        int index[50];
        while (cin >> num_inputs && num_inputs) {
            for (int i = 0; i < num_inputs; i++) cin >> inputs[i];
            iota(index, index + num_inputs, 0);
            sort(index, index + num_inputs, [&inputs](int lhs, int rhs) {
                return inputs[lhs] + inputs[rhs] > inputs[rhs] + inputs[lhs];
            });
            for (int i = 0; i < num_inputs; i++) cout << inputs[index[i]];
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
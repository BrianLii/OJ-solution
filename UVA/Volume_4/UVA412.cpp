/*
    Solution for: UVA 412 - Pi
    Problem Link: https://onlinejudge.org/external/4/412.pdf
    Verdict: Accepted
    Submission ID: 30150908
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        cout << fixed << setprecision(6);
        int input_size, input[50];
        while (cin >> input_size && input_size) {
            int num_coprime = 0;
            for (int i = 0; i < input_size; i++) {
                cin >> input[i];
            }
            for (int i = 0; i < input_size; i++) {
                for (int j = i + 1; j < input_size; j++) {
                    num_coprime += __gcd(input[i], input[j]) == 1;
                }
            }
            if (num_coprime == 0) {
                cout << "No estimate for this data set.\n";
            } else {
                cout << sqrt(3.0 * input_size * (input_size - 1) / num_coprime)
                     << '\n';
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
/*
    Solution for: UVA 516 - Prime Land
    Problem Link: https://onlinejudge.org/external/5/516.pdf
    Verdict: Accepted
    Submission ID: 30150823
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        string input;
        stringstream input_stream;
        while (getline(cin, input) && input != "0") {
            input_stream.clear();
            input_stream << input;
            int divisor, power, number = 1;
            while (input_stream >> divisor >> power) {
                while (power--) number *= divisor;
            }
            vector<int> answer;
            number--;
            for (int i = 2; i * i <= number; i++) {
                if (number % i) continue;
                power = 0;
                while (number % i == 0) {
                    number /= i;
                    power++;
                }
                answer.emplace_back(power);
                answer.emplace_back(i);
            }
            if (number > 1) {
                answer.emplace_back(1);
                answer.emplace_back(number);
            }
            for (int i = answer.size() - 1; i >= 0; i--) {
                cout << answer[i];
                if (i) cout << ' ';
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
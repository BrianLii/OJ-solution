/*
    Solution for: UVA 100 - The 3n + 1 Problem
    Problem Link: https://onlinejudge.org/external/1/100.pdf
    Verdict: Accepted
    Submission ID: 30132333
    Tags: memorization
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    static const int max_num = 1000000;
    static int cycles[max_num + 1];
    int cycle(uint num) {
        int adjust = 0;
        while (num > max_num) {
            adjust++;
            if (num % 2) {
                num = 3 * num + 1;
            } else {
                num /= 2;
            }
        }
        if (adjust) return adjust + cycle(num);

        int &answer = cycles[num];
        if (answer) return answer;
        if (num == 1) return answer = 1;
        if (num % 2 == 0) {
            return answer = 1 + cycle(num / 2);
        } else {
            return answer = 1 + cycle(num * 3 + 1);
        }
    }

   public:
    void solve() {
        for (int i = 1; i <= max_num; i++) {
            cycles[i] = cycle(i);
        }
        int low, high;
        while (cin >> low >> high) {
            cout << low << ' ' << high << ' ';
            if (low > high) swap(low, high);
            cout << *max_element(cycles + low, cycles + high + 1);
            cout << '\n';
        }
    }
};
int Solution::cycles[1000001] = {0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
/*
    Solution for: UVA 10424 - Love Calculator
    Problem Link: https://onlinejudge.org/external/104/10424.pdf
    Verdict: Accepted
    Submission ID: 30127443
    Tags: recursion
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int get_value(int number) {
        if (number < 10) return number;
        int sum = 0;
        while (number) {
            sum += number % 10;
            number /= 10;
        }
        return get_value(sum);
    }
    int get_value(string &name) {
        int sum = 0;
        for (char chr : name) {
            if (isalpha(chr)) {
                sum += tolower(chr) - 'a' + 1;
            }
        }
        return get_value(sum);
    }

   public:
    void solve() {
        string name_1, name_2;
        while (getline(cin, name_1) && getline(cin, name_2)) {
            int value_1 = get_value(name_1);
            int value_2 = get_value(name_2);
            if (value_1 > value_2) swap(value_1, value_2);
            cout << fixed << setprecision(2);
            cout << (double)value_1 / value_2 * 100 << " %\n";
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
/*
    Solution for: UVA 100 - The 3n + 1 Problem
    Problem Link: https://onlinejudge.org/external/1/100.pdf
    Verdict: Accepted
    Submission ID: 30090724
*/

#include <bits/stdc++.h>
using namespace std;

int cycle_length(long long n) {
    int ans = 1;
    while (n > 1) {
        if (n % 2) {
            n = 3 * n + 1;
        } else {
            n /= 2;
        }
        ans++;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int max_num = 1000000;
    vector<int> cycle_lengths(max_num + 1);
    for (int i = 1; i <= max_num; i++) {
        cycle_lengths[i] = cycle_length(i);
    }
    int low_bound = -1, high_bound = -1;
    while (cin >> low_bound >> high_bound) {
        cout << low_bound << ' ' << high_bound << ' ';
        if (low_bound > high_bound) swap(low_bound, high_bound);
        cout << (*max_element(cycle_lengths.begin() + low_bound,
                              cycle_lengths.begin() + high_bound + 1));
        cout << endl;
    }
    return 0;
}

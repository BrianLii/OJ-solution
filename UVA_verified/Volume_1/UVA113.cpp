/*
    Solution for: UVA 113 - Power of Cryptography
    Problem Link: https://onlinejudge.org/external/1/113.pdf
    Verdict: Accepted
    Submission ID: 30091672
*/

#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long double p, n, ans;
    while (cin >> n >> p) {
        cout << fixed << (int)round(pow(p, 1.0 / n)) << '\n';
    }
    return 0;
}

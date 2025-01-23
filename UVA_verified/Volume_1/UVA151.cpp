/*
    Solution for: UVA 151 - Power Crisis
    Problem Link: https://onlinejudge.org/external/1/151.pdf
    Verdict: Accepted
    Submission ID: 30092107
*/

#include <bits/stdc++.h>
using namespace std;

int last_city(int N, int k) {
    int ans = 0;
    for (int i = 2; i <= N - 1; i++) {
        ans = (ans + k) % i;
    }
    return ans + 2;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    while (cin >> N && N) {
        for (int i = 1;; i++) {
            if (last_city(N, i) == 13) {
                cout << i << "\n";
                break;
            }
        }
    }
    return 0;
}

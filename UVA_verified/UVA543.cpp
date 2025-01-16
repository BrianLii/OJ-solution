/*
    Solution for: UVA 543 - Goldbach’s Conjecture
    Problem Link: https://onlinejudge.org/external/5/543.pdf
    Verdict: Accepted
    Submission ID: 30097684
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int not_prime[1000001];
    void sieve(int max_num = 1000000) {
        not_prime[0] = not_prime[1] = 1;
        for (int i = 2; i * i <= max_num; i++) {
            if (not_prime[i]) continue;
            for (int j = i * i; j <= max_num; j += i) {
                not_prime[j] = 1;
            }
        }
    }

   public:
    void solve() {
        sieve();
        int input;
        while (cin >> input && input) {
            for (int i = 3;; i += 2) {
                if (!not_prime[i] && !not_prime[input - i]) {
                    cout << input << " = " << i << " + " << input - i << '\n';
                    break;
                }
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
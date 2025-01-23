/*
    Solution for: UVA 10168 - Summation of Four Primes
    Problem Link: https://onlinejudge.org/external/101/10168.pdf
    Verdict: Accepted
    Submission ID: 30113307
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    const int max_num = 10000000;
    vector<bool> not_prime;
    void sieve() {
        not_prime.resize(max_num + 1);
        not_prime[0] = not_prime[1] = true;
        for (int i = 2; i * i <= max_num; i++) {
            if (!not_prime[i]) {
                for (int j = i * i; j <= max_num; j += i) {
                    not_prime[j] = true;
                }
            }
        }
    }
    int split_even(int num) {
        for (int i = 2; i <= num; i++) {
            if (!not_prime[i] && !not_prime[num - i]) return i;
        }
        assert(false);
    }

   public:
    void solve() {
        sieve();
        int num;
        while (cin >> num) {
            if (num < 8) {
                cout << "Impossible.\n";
                continue;
            }
            if (num % 2 == 0) {
                int split_result = split_even(num - 4);
                cout << "2 2 ";
                cout << split_result << ' ' << num - 4 - split_result << "\n";
            } else {
                int split_result = split_even(num - 5);
                cout << "2 3 ";
                cout << split_result << ' ' << num - 5 - split_result << "\n";
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

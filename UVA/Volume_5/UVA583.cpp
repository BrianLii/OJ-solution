/*
    Solution for: UVA 583 - Prime Factors
    Problem Link: https://onlinejudge.org/external/5/583.pdf
    Verdict: Accepted
    Submission ID: 30153187
    Tags: sieve
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        const int sieve_max = 46340;
        int not_prime[sieve_max + 1] = {1, 1, 0};
        int primes[5000] = {2}, num_primes = 1;
        for (int i = 3; i <= sieve_max; i += 2) {
            if (not_prime[i]) continue;
            primes[num_primes++] = i;
            for (int j = i * i; j <= sieve_max; j += i + i) {
                not_prime[j] = true;
            }
        }
        int number;
        while (cin >> number && number) {
            cout << number << " = ";
            if (number < 0) cout << "-1 x ";
            number = abs(number);
            bool is_first = true;
            for (int i = 0; i < num_primes; i++) {
                if (primes[i] * primes[i] > number) break;
                if (number % primes[i]) continue;
                while (number % primes[i] == 0) {
                    if (is_first) {
                        is_first = false;
                    } else {
                        cout << " x ";
                    }
                    cout << primes[i];
                    number /= primes[i];
                }
            }
            if (number > 1) {
                if (!is_first) cout << " x ";
                cout << number;
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
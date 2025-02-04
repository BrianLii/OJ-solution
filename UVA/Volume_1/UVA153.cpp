/*
    Solution for: UVA 153 - Permalex
    Problem Link: https://onlinejudge.org/external/1/153.pdf
    Verdict: Accepted
    Submission ID: 30130263
    Tags: combinatorics
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int num_permutations(int counts[], int length) {
        vector<int64_t> divisors;
        for (int i = 0; i < 26; i++) {
            for (int j = 2; j <= counts[i]; j++) {
                if (divisors.size() && divisors.back() < 1e8) {
                    divisors.back() *= j;
                } else {
                    divisors.emplace_back(j);
                }
            }
        }
        int64_t answer = 1;
        for (int i = 2; i <= length; i++) {
            answer *= i;
            for (int64_t &divisor : divisors) {
                int64_t gcd = __gcd(answer, divisor);
                divisor /= gcd;
                answer /= gcd;
            }
        }
        return (int)answer;
    }

   public:
    void solve() {
        string input;
        int counts[26], answer;
        while (cin >> input && input != "#") {
            fill(counts, counts + 26, 0);
            answer = 0;
            for (int i = 0; i < input.size(); i++) {
                counts[input[i] - 'a']++;
            }
            for (int i = 0; i < input.size(); i++) {
                for (int j = 0; j < input[i] - 'a'; j++) {
                    if (!counts[j]) continue;
                    counts[j]--;
                    answer += num_permutations(counts, input.size() - i - 1);
                    counts[j]++;
                }
                counts[input[i] - 'a']--;
            }
            cout << setw(10) << answer + 1 << "\n";
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
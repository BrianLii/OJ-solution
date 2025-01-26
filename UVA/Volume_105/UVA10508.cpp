/*
    Solution for: UVA 10508 - Word Morphing
    Problem Link: https://onlinejudge.org/external/105/10508.pdf
    Verdict: Accepted
    Submission ID: 30117400
    Tags: sorting
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int diff(string &word_1, string &word_2) {
        int count = 0;
        for (int i = 0; i < word_1.size(); i++) {
            count += word_1[i] != word_2[i];
        }
        return count;
    }

   public:
    void solve() {
        int num_words, word_len;
        vector<string> words;
        vector<int> index, diffs;
        while (cin >> num_words >> word_len) {
            words.resize(num_words);
            index.resize(num_words);
            diffs.resize(num_words);
            for (string &word : words) cin >> word;
            for (int i = 0; i < num_words; i++) {
                diffs[i] = diff(words[0], words[i]);
            }
            iota(index.begin(), index.end(), 0);
            sort(index.begin(), index.end(), [&diffs](int lhs, int rhs) {
                return diffs[lhs] < diffs[rhs];
            });
            for (int i = 0; i < num_words; i++) {
                cout << words[index[i]] << '\n';
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
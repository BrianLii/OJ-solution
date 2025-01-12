/*
    Solution for:
    Problem Link:
    Verdict: Accepted
    Submission ID:
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        int num_words, error_1;
        string word;
        cin >> num_words;
        while (num_words--) {
            cin >> word;
            error_1 = int(word[0] != 'o') + (word[1] != 'n') + (word[2] != 'e');
            if (word.size() == 5) {
                cout << "3\n";
            } else if (error_1 <= 1) {
                cout << "1\n";
            } else {
                cout << "2\n";
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
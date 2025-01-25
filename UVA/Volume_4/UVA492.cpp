/*
    Solution for: UVA 492 - Pig-Latin
    Problem Link: https://onlinejudge.org/external/4/492.pdf
    Verdict: Accepted
    Submission ID: 30113411
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool is_vowel(char chr) {
        chr = tolower(chr);
        return chr == 'a' || chr == 'e' || chr == 'i' || chr == 'o' ||
               chr == 'u';
    }

   public:
    void solve() {
        string line;
        while (getline(cin, line)) {
            for (int i = 0; i < line.size(); i++) {
                if (!isalpha(line[i])) {
                    cout << line[i];
                    continue;
                }
                int word_end = i;
                for (int j = i; j < line.size(); j++) {
                    if (isalpha(line[j]))
                        word_end = j;
                    else
                        break;
                }
                if (is_vowel(line[i])) {
                    for (int j = i; j <= word_end; j++) {
                        cout << line[j];
                    }
                } else {
                    for (int j = i + 1; j <= word_end; j++) {
                        cout << line[j];
                    }
                    cout << line[i];
                }
                cout << "ay";
                i = word_end;
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
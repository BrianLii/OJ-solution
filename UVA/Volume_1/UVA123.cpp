/*
    Solution for: UVA 123 - Searching Quickly
    Problem Link: https://onlinejudge.org/external/1/123.pdf
    Verdict: Accepted
    Submission ID: 30153106
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        string line, word;
        unordered_set<string> ignores;
        vector<string> lines;
        int line_id = 0;
        vector<tuple<string, int, int>> titles;
        while (getline(cin, line)) {
            if (line == "::") break;
            ignores.emplace(line);
        }
        while (getline(cin, line)) {
            for (char &c : line) c = tolower(c);
            lines.emplace_back(line);
            for (int i = 0; i < line.size(); i++) {
                if (line[i] == ' ') continue;
                word = line[i];
                while (i + 1 < line.size() && line[i + 1] != ' ') {
                    word += line[++i];
                }
                if (ignores.find(word) == ignores.end()) {
                    titles.emplace_back(word, line_id, i - word.size() + 1);
                }
            }
            line_id++;
        }
        sort(titles.begin(), titles.end());
        for (auto title : titles) {
            string &line = lines[get<1>(title)];
            int start = get<2>(title);
            int end = start + get<0>(title).size() - 1;
            for (int i = 0; i < line.size(); i++) {
                if (i < start || end < i) {
                    cout << line[i];
                } else {
                    cout << (char)toupper(line[i]);
                }
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
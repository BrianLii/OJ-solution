/*
    Solution for: UVA 11222 - Only I did it!
    Problem Link: https://onlinejudge.org/external/112/11222.pdf
    Verdict: Accepted
    Submission ID: 30107828
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    void mark_dup(vector<int> &problems_1, vector<int> &problems_2) {
        int current = 0;
        for (int i = 0; i < problems_1.size(); i++) {
            if (problems_1[i] < 0) continue;
            while (current < problems_2.size() &&
                   problems_2[current] < problems_1[i]) {
                current++;
            }
            if (current < problems_2.size() &&
                problems_2[current] == problems_1[i]) {
                problems_1[i] *= -1;
            }
        }
    }

   public:
    void solve() {
        int num_cases;
        vector<int> problems[3], results[3];
        cin >> num_cases;
        for (int case_id = 1; case_id <= num_cases; case_id++) {
            for (int i = 0; i < 3; i++) {
                int num_problems;
                cin >> num_problems;
                problems[i].resize(num_problems);
                results[i].clear();
                for (int j = 0; j < num_problems; j++) {
                    cin >> problems[i][j];
                }
                sort(problems[i].begin(), problems[i].end());
                problems[i].resize(
                    unique(problems[i].begin(), problems[i].end()) -
                    problems[i].begin());
            }
            for (int i = 0; i < 3; i++) {
                mark_dup(problems[i], problems[(i + 1) % 3]);
                mark_dup(problems[i], problems[(i + 2) % 3]);
                for (int j = 0; j < problems[i].size(); j++) {
                    if (problems[i][j] > 0)
                        results[i].emplace_back(problems[i][j]);
                    else
                        problems[i][j] *= -1;
                }
            }

            cout << "Case #" << case_id << ":\n";
            int max_results =
                max({results[0].size(), results[1].size(), results[2].size()});
            for (int i = 0; i < 3; i++) {
                if (results[i].size() == max_results) {
                    cout << i + 1 << ' ';
                    cout << max_results;
                    for (int j : results[i]) cout << ' ' << j;
                    cout << "\n";
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
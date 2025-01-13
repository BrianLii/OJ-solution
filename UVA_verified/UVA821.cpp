/*
    Solution for: UVA 821 - Page Hopping
    Problem Link: https://onlinejudge.org/external/8/821.pdf
    Verdict: Accepted
    Submission ID: 30097532
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int dist[101][101];
    int used[101];
    const int INF = 200;
    bool solve_one(int case_id) {
        for (int i = 1; i <= 100; i++) {
            fill(dist[i] + 1, dist[i] + 100 + 1, INF);
        }

        int from, to;
        cin >> from >> to;
        if (!from) return false;
        do {
            dist[from][to] = 1;
            used[from] = used[to] = case_id;
        } while (cin >> from >> to && from && to);

        for (int k = 1; k <= 100; k++) {
            if (used[k] != case_id) continue;
            for (int i = 1; i <= 100; i++) {
                if (used[i] != case_id) continue;
                for (int j = 1; j <= 100; j++) {
                    if (used[j] != case_id) continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        double dist_sum = 0, dist_count = 0;
        for (int i = 1; i <= 100; i++) {
            if (used[i] != case_id) continue;
            for (int j = 1; j <= 100; j++) {
                if (used[j] != case_id || i == j) continue;
                dist_count++;
                dist_sum += dist[i][j];
            }
        }

        cout << "Case " << case_id
             << ": average length between pages = " << fixed << setprecision(3)
             << dist_sum / dist_count << " clicks\n";
        return true;
    }

   public:
    void solve() { for (int case_id = 1; solve_one(case_id); case_id++); }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
/*
    Solution for: UVA 11518 - Dominos 2
    Problem Link: https://onlinejudge.org/external/115/11518.pdf
    Verdict: Accepted
    Submission ID: 30096844
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> graph[10001];
    int visited[10001];
    void dfs(int current) {
        visited[current] = 1;
        for (int node : graph[current]) {
            if (!visited[node]) dfs(node);
        }
    }
    void solve_one() {
        int num_nodes, num_edges, num_init;
        cin >> num_nodes >> num_edges >> num_init;
        for (int i = 1; i <= num_nodes; i++) {
            graph[i].clear();
            visited[i] = 0;
        }
        while (num_edges--) {
            int from, to;
            cin >> from >> to;
            graph[from].emplace_back(to);
        }
        while (num_init--) {
            int start;
            cin >> start;
            dfs(start);
        }
        cout << accumulate(visited + 1, visited + num_nodes + 1, 0) << "\n";
    }

   public:
    void solve() {
        int num_cases;
        cin >> num_cases;
        while (num_cases--) {
            solve_one();
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
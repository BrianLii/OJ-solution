/*
    Solution for: UVA 11749 - Poor Trade Advisor
    Problem Link: https://onlinejudge.org/external/117/11749.pdf
    Verdict: Accepted
    Submission ID: 30096870
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct DSU {
        int head[501], set_sizes[501];
        void init(int num_nodes) {
            iota(head + 1, head + num_nodes + 1, 1);
            fill(set_sizes + 1, set_sizes + num_nodes + 1, 1);
        }
        int find(int node) {
            if (head[node] == node) return node;
            return head[node] = find(head[node]);
        }
        void connect(int node_1, int node_2) {
            if (connected(node_1, node_2)) return;
            node_1 = find(node_1);
            node_2 = find(node_2);
            head[node_1] = node_2;
            set_sizes[node_2] += set_sizes[node_1];
        }
        bool connected(int node_1, int node_2) {
            return find(node_1) == find(node_2);
        }
    } dsu;
    bool solve_one() {
        int num_nodes, num_edges, max_ppa = INT_MIN;
        cin >> num_nodes >> num_edges;
        if (num_nodes == 0) return false;
        vector<vector<int>> edges(num_edges, vector<int>(3));
        for (vector<int> &edge : edges) {
            cin >> edge[0] >> edge[1] >> edge[2];
            if (edge[2] > max_ppa) max_ppa = edge[2];
        }
        dsu.init(num_nodes);
        for (vector<int> &edge : edges) {
            if (edge[2] == max_ppa) {
                dsu.connect(edge[0], edge[1]);
            }
        }
        cout << *max_element(dsu.set_sizes + 1, dsu.set_sizes + num_nodes + 1)
             << '\n';
        return true;
    }

   public:
    void solve() { while (solve_one()); }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
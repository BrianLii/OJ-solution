/*
    Solution for: UVA 10099: The Tourist Guide
    Problem Link: https://onlinejudge.org/external/100/10099.pdf
    Verdict: Accepted
    Submission ID: 30095657
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct DSU {
        int head[101];
        void init(int num_nodes) { iota(head + 1, head + num_nodes + 1, 1); }
        int find(int node) {
            if (head[node] == node) {
                return node;
            } else {
                return head[node] = find(head[node]);
            }
        }
        void connect(int node_1, int node_2) {
            head[find(node_1)] = find(node_2);
        }
        bool connected(int node_1, int node_2) {
            return find(node_1) == find(node_2);
        }
    } dsu;

    void solve_one(int num_nodes, int num_edges) {
        dsu.init(num_nodes);
        priority_queue<vector<int>> edges_heap;
        for (int i = 1; i <= num_edges; i++) {
            int from, to, cost;
            cin >> from >> to >> cost;
            edges_heap.emplace(vector<int>({cost, from, to}));
        }

        int start, term, num_tourists;
        cin >> start >> term >> num_tourists;
        while (edges_heap.size()) {
            vector<int> edge = edges_heap.top();
            dsu.connect(edge[1], edge[2]);
            if (dsu.connected(start, term)) {
                int cost = num_tourists / (edge[0] - 1) +
                           (num_tourists % (edge[0] - 1) != 0);
                cout << "Minimum Number of Trips = " << cost << "\n\n";
                break;
            }
            edges_heap.pop();
        }
    }

   public:
    void solve() {
        int num_nodes, num_edges;
        for (int i = 1; cin >> num_nodes >> num_edges && num_nodes; i++) {
            cout << "Scenario #" << i << "\n";
            solve_one(num_nodes, num_edges);
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
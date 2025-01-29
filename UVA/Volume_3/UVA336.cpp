/*
    Solution for: UVA 336 - A Node Too Far
    Problem Link: https://onlinejudge.org/external/3/336.pdf
    Verdict: Accepted
    Submission ID: 30120598
    Tags: bfs
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<int, int> node_id;
    int get_node_id(int node) {
        if (node_id.find(node) != node_id.end()) {
            return node_id[node];
        } else {
            return node_id[node] = node_id.size();
        }
    }
    int get_reachable(int start, int ttl, vector<int> edges[]) {
        static int depth[30];
        int reachable = 0, current;
        queue<int> que;
        fill(depth, depth + node_id.size(), -1);
        que.emplace(start);
        depth[start] = 0;
        while (que.size()) {
            current = que.front();
            que.pop();
            reachable++;
            if (depth[current] == ttl) continue;
            for (int i : edges[current]) {
                if (depth[i] != -1) continue;
                depth[i] = depth[current] + 1;
                que.emplace(i);
            }
        }
        return reachable;
    }

   public:
    void solve() {
        int num_edges, case_id = 0;
        vector<int> edges[30];
        while (cin >> num_edges && num_edges) {
            for (int i = 0; i < 30; i++) edges[i].clear();
            node_id.clear();
            int from, to;
            for (int i = 0; i < num_edges; i++) {
                cin >> from >> to;
                from = get_node_id(from);
                to = get_node_id(to);
                edges[from].emplace_back(to);
                edges[to].emplace_back(from);
            }
            int start, ttl;
            while (cin >> start >> ttl && start) {
                int start_id = get_node_id(start);
                int reachable = get_reachable(start_id, ttl, edges);
                cout << "Case " << ++case_id << ": "
                     << node_id.size() - reachable
                     << " nodes not reachable from node " << start
                     << " with TTL = " << ttl << ".\n";
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
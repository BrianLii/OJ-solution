/*
    Solution for: UVA 10034 - Freckles
    Problem Link: https://onlinejudge.org/external/100/10034.pdf
    Verdict: Accepted
    Submission ID: 30117380
    Tags: mst kruskal
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    double square(double x) { return x * x; }
    double dist(double node_1[2], double node_2[2]) {
        return sqrt(square(node_1[0] - node_2[0]) +
                    square(node_1[1] - node_2[1]));
    }
    struct DSU {
        int lead[100];
        void init(int num_nodes) { iota(lead, lead + num_nodes, 0); }
        int find(int node) {
            if (lead[node] == node) return node;
            return lead[node] = find(lead[node]);
        }
        void connect(int node_1, int node_2) {
            lead[find(node_1)] = find(node_2);
        }
        bool connected(int node_1, int node_2) {
            return find(node_1) == find(node_2);
        }
    };

   public:
    void solve() {
        int num_cases, num_nodes;
        double nodes[100][2];
        typedef vector<int> Segment;
        DSU dsu;
        cin >> num_cases;
        while (num_cases--) {
            cin >> num_nodes;
            for (int i = 0; i < num_nodes; i++) {
                cin >> nodes[i][0] >> nodes[i][1];
            }
            dsu.init(num_nodes);
            vector<Segment> segments;
            for (int i = 0; i < num_nodes; i++) {
                for (int j = i + 1; j < num_nodes; j++) {
                    segments.push_back({i, j});
                }
            }
            sort(segments.begin(), segments.end(),
                 [&nodes, this](const Segment &lhs, const Segment &rhs) {
                     return dist(nodes[lhs[0]], nodes[lhs[1]]) <
                            dist(nodes[rhs[0]], nodes[rhs[1]]);
                 });
            double cost = 0;
            for (Segment &segment : segments) {
                if (dsu.connected(segment[0], segment[1])) continue;
                cost += dist(nodes[segment[0]], nodes[segment[1]]);
                dsu.connect(segment[0], segment[1]);
            }
            cout << fixed << setprecision(2) << cost << "\n";
            if (num_cases) cout << "\n";
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
/*
    Solution for: UVA 341 - Non-Stop Travel
    Problem Link: https://onlinejudge.org/external/3/341.pdf
    Verdict: Accepted
    Submission ID: 30131000
    Tags: sssp dijkstra
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        typedef pair<int, int> Edge;
        typedef pair<int, int> HeapNode;
        int num_nodes, case_id = 0;
        vector<Edge> edges[11];
        int dist[11], visited[11], parent[11];
        while (cin >> num_nodes && num_nodes) {
            for (int i = 1; i <= num_nodes; i++) {
                dist[i] = INT_MAX;
                visited[i] = false;
            }
            for (int i = 1, num_edges; i <= num_nodes; i++) {
                cin >> num_edges;
                edges[i].resize(num_edges);
                for (int j = 0; j < num_edges; j++) {
                    cin >> edges[i][j].first >> edges[i][j].second;
                }
            }
            int start, end;
            cin >> start >> end;
            priority_queue<HeapNode, vector<HeapNode>, greater<HeapNode>> heap;
            dist[start] = 0;
            heap.emplace(0, start);
            while (heap.size()) {
                int current = heap.top().second;
                heap.pop();
                if (visited[current]) continue;
                visited[current] = true;
                for (Edge edge : edges[current]) {
                    if (dist[edge.first] > dist[current] + edge.second) {
                        dist[edge.first] = dist[current] + edge.second;
                        parent[edge.first] = current;
                        heap.emplace(dist[edge.first], edge.first);
                    }
                }
            }
            vector<int> path;
            int current = end;
            path.emplace_back(end);
            while (current != start) {
                current = parent[current];
                path.emplace_back(current);
            }
            cout << "Case " << ++case_id << ": Path =";
            for (int i = path.size() - 1; i >= 0; i--) {
                cout << ' ' << path[i];
            }
            cout << "; " << dist[end] << " second delay\n";
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
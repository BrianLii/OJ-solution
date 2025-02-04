/*
    Solution for: UVA 11492 - Babel
    Problem Link: https://onlinejudge.org/external/114/11492.pdf
    Verdict: Accepted
    Submission ID: 30130960
    Tags: sssp dijkstra
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct Edge {
        int to, length, initial;
        Edge(int to, int length, int initial)
            : to(to), length(length), initial(initial) {}
    };
    struct HeapNode {
        int dist, lang, initial;
        HeapNode(int dist, int lang, int initial)
            : dist(dist), lang(lang), initial(initial) {}
    };
    struct HeapCmp {
        bool operator()(const HeapNode &lhs, const HeapNode &rhs) {
            return lhs.dist > rhs.dist;
        }
    };
    unordered_map<string, int> ids;
    int to_id(string &word) {
        if (ids.find(word) == ids.end()) {
            return ids[word] = ids.size();
        } else {
            return ids[word];
        }
    }

   public:
    void solve() {
        const int max_lang = 4002;
        int num_words;
        int dist[4002][26], visited[4002][26] = {0};
        vector<Edge> edges[4002];
        for (int i = 0; i < max_lang; i++) {
            fill(dist[i], dist[i] + 26, INT_MAX);
        }

        while (cin >> num_words && num_words) {
            int start, finish, from, to;
            string from_str, to_str, word;
            cin >> from_str >> to_str;
            start = to_id(from_str);
            finish = to_id(to_str);
            priority_queue<HeapNode, vector<HeapNode>, HeapCmp> heap;
            for (int i = 0; i < num_words; i++) {
                cin >> from_str >> to_str >> word;
                from = to_id(from_str);
                to = to_id(to_str);
                edges[from].emplace_back(to, word.size(), word[0] - 'a');
                edges[to].emplace_back(from, word.size(), word[0] - 'a');
            }
            for (int i = 0; i < 26; i++) {
                dist[start][i] = 0;
                heap.emplace(dist[start][i], start, i);
            }

            while (heap.size()) {
                HeapNode curr = heap.top();
                heap.pop();
                if (visited[curr.lang][curr.initial]) continue;
                visited[curr.lang][curr.initial] = true;
                for (Edge &edge : edges[curr.lang]) {
                    if (edge.initial == curr.initial) continue;
                    if (visited[edge.to][edge.initial]) continue;
                    if (dist[edge.to][edge.initial] > curr.dist + edge.length) {
                        dist[edge.to][edge.initial] = curr.dist + edge.length;
                        heap.emplace(dist[edge.to][edge.initial], edge.to,
                                     edge.initial);
                    }
                }
            }

            int answer = *min_element(dist[finish], dist[finish] + 26);
            if (answer == INT_MAX) {
                cout << "impossivel\n";
            } else {
                cout << answer << '\n';
            }

            for (int i = 0; i < ids.size(); i++) {
                edges[i].clear();
                fill(dist[i], dist[i] + 26, INT_MAX);
                fill(visited[i], visited[i] + 26, false);
            }
            ids.clear();
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
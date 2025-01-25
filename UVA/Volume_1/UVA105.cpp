/*
    Solution for: UVA 105 - The Skyline Problem
    Problem Link: https://onlinejudge.org/external/1/105.pdf
    Verdict: Accepted
    Submission ID: 30090910
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<int>> buildings;
    for (int min_x, max_x, height; cin >> min_x >> height >> max_x;) {
        buildings.push_back({min_x, max_x, height});
    }

    vector<int> x_ords;
    for (int i = 0; i < buildings.size(); i++) {
        x_ords.emplace_back(buildings[i][0]);
        x_ords.emplace_back(buildings[i][1]);
    }
    sort(x_ords.begin(), x_ords.end());
    x_ords.resize(unique(x_ords.begin(), x_ords.end()) - x_ords.begin());

    priority_queue<pair<int, int>> heap;
    vector<vector<int>> ans;
    int next_building = 0, prev_y = -1;

    heap.emplace(0, INT_MAX);
    for (int x_ord : x_ords) {
        while (next_building < buildings.size() &&
               buildings[next_building][0] == x_ord) {
            heap.emplace(buildings[next_building][2],
                         buildings[next_building][1]);
            next_building++;
        }
        while (heap.size() && heap.top().second <= x_ord) heap.pop();

        if (prev_y != heap.top().first) {
            if (~prev_y) cout << ' ';
            cout << x_ord << ' ' << (prev_y = heap.top().first);
        }
    }
    cout << '\n';
    return 0;
}

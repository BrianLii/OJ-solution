/*
    Solution for: UVA 102 - Ecological Bin Packing
    Problem Link: https://onlinejudge.org/external/1/102.pdf
    Verdict: Accepted
    Submission ID: 30090839
*/

#include <bits/stdc++.h>
#define B 0
#define C 1
#define G 2
using namespace std;

int get_cost(int (*num)[3], int config[3]) {
    int ans = 0;
    for (int i = 0; i < 3; i++) {
        ans += num[i][(config[i] + 1) % 3] + num[i][(config[i] + 2) % 3];
    }
    return ans;
}

void dfs(int (*num)[3], int depth, int todo, int config[3], int best_config[3],
         int &min_cost) {
    if (depth == 3) {
        int cost = get_cost(num, config);
        if (cost < min_cost) {
            copy(config, config + 3, best_config);
            min_cost = cost;
        }
        return;
    }
    for (int i = 0; i < 3; i++) {
        if (todo >> i & 1) {
            config[depth] = i;
            dfs(num, depth + 1, todo ^ (1 << i), config, best_config, min_cost);
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int num[3][3], config[3], best_config[3], min_cost;
    while (cin >> num[0][B] >> num[0][G] >> num[0][C]) {
        cin >> num[1][B] >> num[1][G] >> num[1][C];
        cin >> num[2][B] >> num[2][G] >> num[2][C];

        min_cost = INT_MAX;
        dfs(num, 0, (1 << 3) - 1, config, best_config, min_cost);
        for (int i = 0; i < 3; i++) cout << "BCG"[best_config[i]];
        cout << ' ' << min_cost << endl;
    }
    return 0;
}

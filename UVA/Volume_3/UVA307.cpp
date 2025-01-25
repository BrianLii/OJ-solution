/*
    Solution for: UVA 307 - Sticks
    Problem Link: https://onlinejudge.org/external/3/307.pdf
    Verdict: Accepted
    Submission ID: 30107337
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
    int sticks[100], num_sticks, target;
    bool dfs(int current, int position, int num_left) {
        if (current == target) {
            return num_left == 0 || dfs(0, 0, num_left);
        }
        if (position == num_sticks) return false;
        if (sticks[position] < 0 ||
            (position && sticks[position - 1] == sticks[position])) {
            return dfs(current, position + 1, num_left);
        }

        current += sticks[position];
        sticks[position] -= 64;
        if (current <= target && dfs(current, position + 1, num_left - 1)) {
            return true;
        }
        sticks[position] += 64;
        current -= sticks[position];
        if (!current || current + sticks[position] == target) return false;
        return dfs(current, position + 1, num_left);
    }

   public:
    void solve() {
        while (cin >> num_sticks && num_sticks) {
            int sum_sticks = 0, max_stick = 0, min_stick = 51;
            for (int i = 0; i < num_sticks; i++) {
                cin >> sticks[i];
                sum_sticks += sticks[i];
            }
            sort(sticks, sticks + num_sticks, greater<int>());
            min_stick = sticks[num_sticks - 1];
            max_stick = sticks[0];
            int answer = sum_sticks;
            for (int i = max_stick; i <= sum_sticks / 2; i++) {
                target = i;
                if (sum_sticks % i == 0 && dfs(0, 0, num_sticks)) {
                    answer = i;
                    break;
                }
            }
            cout << answer << "\n";
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}

/*
Reference 1:
https://naivered.github.io/2016/04/08/Problem_Solving/UVa/UVa-307-Sticks/
Reference 2: https://www.cnblogs.com/KeepZ/p/13789135.html
*/
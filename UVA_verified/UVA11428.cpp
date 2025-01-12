/*
    Solution for: UVA 11428 - Cubes
    Problem Link: https://onlinejudge.org/external/114/11428.pdf
    Verdict: Accepted
    Submission ID: 30096337
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    /*
           x^3 + y^3 = (x-y) * (x^2 + xy + y^2)
        => x^3 + y^3 = z * w
        => (z + y)^2 + (z + y)y + y^2 = w
        => z^2 + 2zy + y^2 + zy + y^2 + y^2 = w
        => 3y^2 + 3zy + z^2 = w
    */
    void find_x_y(int z, int w, int &ans_x, int &ans_y) {
        int low_y = 1, high_y = 58;
        while (low_y <= high_y) {
            int y = (low_y + high_y) / 2;
            int lhs = 3 * y * y + 3 * z * y + z * z;
            if (lhs < w) {
                low_y = y + 1;
            } else if (lhs == w) {
                if (y < ans_y) {
                    ans_x = y + z;
                    ans_y = y;
                }
                break;
            } else {
                high_y = y - 1;
            }
        }
    }
    void solve_one(int N) {
        int ans_x = INT_MAX, ans_y = INT_MAX;
        for (int i = 1; i * i <= N; i++) {
            if (N % i == 0) {
                find_x_y(i, N / i, ans_x, ans_y);
                find_x_y(N / i, i, ans_x, ans_y);
            }
        }
        if (ans_y == INT_MAX) {
            cout << "No solution\n";
        } else {
            cout << ans_x << ' ' << ans_y << "\n";
        }
    }

   public:
    void solve() {
        int N;
        while (cin >> N && N) {
            solve_one(N);
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
/*
    Solution for: UVA 11486 - Finding Paths in Grid
    Problem Link: https://onlinejudge.org/external/114/11486.pdf
    Verdict: Accepted
    Submission ID: 30097271
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    static const int num_states = 35;  // C(7, 3)
    static const int mod = 1000000007;
    struct Matrix {
        static const int dim = num_states;
        int data[dim][dim] = {0};
        struct Matrix operator+(struct Matrix rhs) {
            struct Matrix result;
            for (int i = 0; i < dim; i++) {
                for (int j = 0; j < dim; j++) {
                    result[i][j] = (data[i][j] + rhs[i][j]) % mod;
                }
            }
            return result;
        }
        struct Matrix operator*(struct Matrix rhs) {
            struct Matrix result;
            for (int i = 0; i < dim; i++) {
                for (int j = 0; j < dim; j++) {
                    result[i][j] = 0;
                    for (int k = 0; k < dim; k++) {
                        result[i][j] += (long long)data[i][k] * rhs[k][j] % mod;
                        result[i][j] %= mod;
                    }
                }
            }
            return result;
        }
        int *operator[](int index) { return data[index]; }
        void operator=(struct Matrix rhs) {
            for (int i = 0; i < dim; i++) {
                for (int j = 0; j < dim; j++) {
                    data[i][j] = rhs[i][j];
                }
            }
        }
        struct Matrix power(int exponent) {
            Matrix result, temp_power_2 = *this;
            result.set_identity();
            while (exponent) {
                if (exponent & 1) result = result * temp_power_2;
                exponent >>= 1;
                temp_power_2 = temp_power_2 * temp_power_2;
            }
            return result;
        }
        void set_identity() {
            memset(data, 0, sizeof(data));
            for (int i = 0; i < dim; i++) data[i][i] = 1;
        }
    };
    bool is_adjacent(int state_1, int state_2, int depth) {
        if (depth == 7) return true;
        if (state_1 >> depth & 1 ^ 1)
            return is_adjacent(state_1, state_2, depth + 1);
        return depth != 0 && (state_2 >> (depth - 1) & 1) &&
                   is_adjacent(state_1, state_2 ^ (1 << (depth - 1)),
                               depth + 1) ||
               depth != 6 && (state_2 >> (depth + 1) & 1) &&
                   is_adjacent(state_1, state_2 ^ (1 << (depth + 1)),
                               depth + 1);
    }

   public:
    void solve() {
        vector<int> states;
        for (int i = 0; i < 7; i++)
            for (int j = i + 1; j < 7; j++)
                for (int k = j + 1; k < 7; k++)
                    for (int l = k + 1; l < 7; l++) {
                        states.emplace_back((1 << i) | (1 << j) | (1 << k) |
                                            (1 << l));
                    }
        sort(states.begin(), states.end());

        Matrix adjacent;
        for (int i = 0; i < num_states; i++) {
            for (int j = 0; j < num_states; j++) {
                adjacent[i][j] = is_adjacent(states[i], states[j], 0);
            }
        }

        int num_cases;
        cin >> num_cases;
        while (num_cases--) {
            int num_cols, start_state = 0;
            cin >> num_cols;
            for (int i = 0, input; i < 7; i++) {
                cin >> input;
                if (input != 0) start_state |= 1 << i;
            }
            start_state =
                lower_bound(states.begin(), states.end(), start_state) -
                states.begin();
            Matrix power = adjacent.power(num_cols - 1);
            int ans = 0;
            for (int i = 0; i < num_states; i++) {
                ans = (ans + power[start_state][i]) % mod;
            }
            cout << ans << '\n';
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
/*
    Solution for: UVA 108 - Maximum Sum
    Problem Link: https://onlinejudge.org/external/1/108.pdf
    Verdict: Accepted
    Submission ID: 30091665
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr_size;
    cin >> arr_size;
    vector<vector<int>> arr(arr_size + 1, vector<int>(arr_size + 1));
    for (int i = 1; i <= arr_size; i++) {
        for (int j = 1; j <= arr_size; j++) {
            cin >> arr[i][j];
            arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
        }
    }
    int ans = -128;
    for (int top = 1; top <= arr_size; top++) {
        for (int bot = top; bot <= arr_size; bot++) {
            int max_tail = -128;
            for (int col = 1; col <= arr_size; col++) {
                int col_sum = arr[bot][col] - arr[top - 1][col] -
                              arr[bot][col - 1] + arr[top - 1][col - 1];
                max_tail = max(max_tail, 0) + col_sum;
                ans = max(ans, max_tail);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}

/*
    Solution for: UVA 222 - Budget Travel
    Problem Link: https://onlinejudge.org/external/2/222.pdf
    Verdict: Accepted
    Submission ID: 30127371
    Tags: dp
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        double destination;
        double capacity, miles_gallon;
        int num_stations;
        double locations[52], prices[52], costs[52];
        int case_id = 0;
        while (cin >> destination && destination != -1) {
            cin >> capacity >> miles_gallon >> costs[0] >> num_stations;
            for (int i = 1; i <= num_stations; i++) {
                cin >> locations[i] >> prices[i];
            }
            locations[0] = 0;
            locations[num_stations + 1] = destination;
            prices[num_stations + 1] = 0;
            for (int i = 1; i <= num_stations + 1; i++) {
                costs[i] = -1;
                for (int j = i - 1; j >= 0; j--) {
                    if (capacity * miles_gallon < locations[i] - locations[j])
                        break;
                    double gallons =
                        (locations[i] - locations[j]) / miles_gallon;
                    double new_cost =
                        costs[j] + 2 + round(gallons * prices[i]) / 100;
                    if (costs[i] == -1 || new_cost < costs[i]) {
                        costs[i] = new_cost;
                    }
                }
            }
            cout << "Data Set #" << ++case_id << "\nminimum cost = $" << fixed
                 << setprecision(2) << costs[num_stations + 1] - 2 << '\n';
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
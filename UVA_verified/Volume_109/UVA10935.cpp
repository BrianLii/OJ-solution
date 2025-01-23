/*
    Solution for: UVA 10935 - Throwing cards away
    Problem Link: https://onlinejudge.org/external/109/10935.pdf
    Verdict: Accepted
    Submission ID:
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve() {
        int num_cards;
        while (cin >> num_cards && num_cards) {
            if (num_cards == 1) {
                cout << "Discarded cards:\n";
                cout << "Remaining card: 1\n";
                continue;
            }
            queue<int> cards;
            for (int i = 1; i <= num_cards; i++) {
                cards.emplace(i);
            }
            cout << "Discarded cards: ";
            while (cards.size() >= 2) {
                cout << cards.front();
                cards.pop();
                if (cards.size() >= 2) cout << ", ";
                cards.emplace(cards.front());
                cards.pop();
            }
            cout << "\nRemaining card: ";
            cout << cards.front() << '\n';
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
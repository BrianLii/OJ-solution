/*
    Solution for: UVA 170 - Clock Patience
    Problem Link: https://onlinejudge.org/external/1/170.pdf
    Verdict: Accepted
    Submission ID: 30112824
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int get_next(string &card) {
        const string table = "A23456789TJQK";
        for (int i = 0; i < 13; i++) {
            if (card[0] == table[i]) return i;
        }
        assert(false);
    }

   public:
    void solve() {
        string deck[13][4];
        int deck_top[13];
        while (cin >> deck[12][0] && deck[12][0] != "#") {
            for (int i = 0; i < 4; i++) {
                for (int j = 12; j >= 0; j--) {
                    if (j != 12 || i != 0) cin >> deck[j][i];
                }
            }
            fill(deck_top, deck_top + 13, 0);
            int current_deck = 12, next_deck, flip_count = 0;
            string current_card;
            while (deck_top[current_deck] != 4) {
                flip_count++;
                current_card = deck[current_deck][deck_top[current_deck]];
                next_deck = get_next(current_card);
                deck_top[current_deck]++;
                current_deck = next_deck;
            }
            cout << setfill('0') << setw(2) << flip_count << ",";
            cout << current_card << '\n';
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
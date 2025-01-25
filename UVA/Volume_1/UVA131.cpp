/*
    Solution for: UVA 131 - The Psychic Poker Player
    Problem Link: https://onlinejudge.org/external/1/131.pdf
    Verdict: Accepted
    Submission ID: 30114696
*/

#include <bits/stdc++.h>
#define FACE 0
#define SUIT 1
using namespace std;

class Solution {
    int suit_toi(char chr) {
        const string pattern = "CDHS";
        for (int i = 0; i < 4; i++) {
            if (pattern[i] == chr) return i;
        }
        assert(false);
    }
    int face_toi(char chr) {
        const string pattern = "A23456789TJQK";
        for (int i = 0; i < 13; i++) {
            if (pattern[i] == chr) return i;
        }
        assert(false);
    }
    bool is_straight(int hand[5][2]) {
        int faces[5];
        for (int i = 0; i < 5; i++) faces[i] = hand[i][FACE];
        sort(faces, faces + 5);
        if (faces[1] + 1 != faces[2]) return false;
        if (faces[2] + 1 != faces[3]) return false;
        if (faces[3] + 1 != faces[4]) return false;
        if (faces[0] + 1 == faces[1]) return true;
        return faces[0] == 0 && faces[4] == 12;
    }
    bool is_4(int hand[5][2]) {
        int faces[5];
        for (int i = 0; i < 5; i++) faces[i] = hand[i][FACE];
        sort(faces, faces + 5);
        if (faces[1] != faces[2] || faces[2] != faces[3]) return false;
        return faces[0] == faces[1] || faces[3] == faces[4];
    }
    bool is_2_3(int hand[5][2]) {
        int faces[5];
        for (int i = 0; i < 5; i++) faces[i] = hand[i][FACE];
        sort(faces, faces + 5);
        if (faces[0] != faces[1] || faces[3] != faces[4]) return false;
        return faces[1] == faces[2] || faces[2] == faces[3];
    }
    bool is_3(int hand[5][2]) {
        int faces[5];
        for (int i = 0; i < 5; i++) faces[i] = hand[i][FACE];
        sort(faces, faces + 5);
        if (faces[1] != faces[2]) {
            return faces[2] == faces[3] && faces[3] == faces[4];
        } else {
            return faces[0] == faces[1] || faces[2] == faces[3];
        }
    }
    bool is_2_2(int hand[5][2]) {
        int faces[5];
        for (int i = 0; i < 5; i++) faces[i] = hand[i][FACE];
        sort(faces, faces + 5);
        if (faces[0] != faces[1]) {
            return faces[1] == faces[2] && faces[3] == faces[4];
        } else {
            return faces[2] == faces[3] || faces[3] == faces[4];
        }
    }
    bool is_2(int hand[5][2]) {
        int faces[5];
        for (int i = 0; i < 5; i++) faces[i] = hand[i][FACE];
        sort(faces, faces + 5);
        if (faces[0] == faces[1]) return true;
        if (faces[1] == faces[2]) return true;
        if (faces[2] == faces[3]) return true;
        return faces[3] == faces[4];
    }
    bool is_flush(int hand[5][2]) {
        if (hand[0][SUIT] != hand[1][SUIT]) return false;
        if (hand[1][SUIT] != hand[2][SUIT]) return false;
        if (hand[2][SUIT] != hand[3][SUIT]) return false;
        return hand[3][SUIT] == hand[4][SUIT];
    }
    int get_type(int hand[5][2]) {
        bool flush = is_flush(hand);
        bool straight = is_straight(hand);
        if (flush && straight) return 0;
        if (is_4(hand)) return 1;
        if (is_2_3(hand)) return 2;
        if (flush) return 3;
        if (straight) return 4;
        if (is_3(hand)) return 5;
        if (is_2_2(hand)) return 6;
        if (is_2(hand)) return 7;
        return 8;
    }
    string type_to_str(int type) {
        const string names[] = {
            "straight-flush", "four-of-a-kind", "full-house",
            "flush",          "straight",       "three-of-a-kind",
            "two-pairs",      "one-pair",       "highest-card"};
        return names[type];
    }
    int dfs(int hand[5][2], int deck[5][2], int current[5][2], int size,
            int position) {
        if (size == 5) {
            return get_type(current);
        }
        if (position >= 5) {
            current[size][FACE] = deck[position - 5][FACE];
            current[size][SUIT] = deck[position - 5][SUIT];
            return dfs(hand, deck, current, size + 1, position + 1);
        }
        int case_1 = dfs(hand, deck, current, size, position + 1);
        current[size][FACE] = hand[position][FACE];
        current[size][SUIT] = hand[position][SUIT];
        return min(case_1, dfs(hand, deck, current, size + 1, position + 1));
    }

   public:
    void solve() {
        int hand[5][2], deck[5][2], current[5][2];
        string input;
        while (cin >> input) {
            cout << "Hand: ";
            cout << input << ' ';
            hand[0][FACE] = face_toi(input[FACE]);
            hand[0][SUIT] = suit_toi(input[SUIT]);
            for (int i = 1; i < 5; i++) {
                cin >> input;
                cout << input << ' ';
                hand[i][FACE] = face_toi(input[FACE]);
                hand[i][SUIT] = suit_toi(input[SUIT]);
            }
            cout << "Deck: ";
            for (int i = 0; i < 5; i++) {
                cin >> input;
                cout << input << ' ';
                deck[i][FACE] = face_toi(input[FACE]);
                deck[i][SUIT] = suit_toi(input[SUIT]);
            }
            cout << "Best hand: ";
            cout << type_to_str(dfs(hand, deck, current, 0, 0)) << "\n";
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution().solve();
    return 0;
}
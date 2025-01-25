/*
    Solution for: UVA 128 - Software CRC
    Problem Link: https://onlinejudge.org/external/1/128.pdf
    Verdict: Accepted
    Submission ID: 30091829
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    char input[1026] = "";
    const int G = 34943;
    while (fgets(input, 1026, stdin)) {
        if (!strcmp(input, "#\n")) return 0;
        long long binary = 0;
        for (int i = 0; input[i] != '\n'; i++) {
            binary = ((binary << 8) + input[i]) % G;
        }
        long long CRC = (G - (binary << 16) % G) % G;
        int mask = (1 << 4) - 1;
        printf("%02X %02X\n", CRC >> 8 & 0xff, CRC & 0xff);
    }
    return 0;
}

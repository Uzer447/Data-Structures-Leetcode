#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string pushDominoes(string s) {
        int n = s.size(), prev = -1;
        char prevc = 'L';
        for (int i = 0; i <= n; ++i) {
            char curc = i == n ? 'R' : s[i];
            if (i == n || curc != '.') {
                if (prevc == curc) {
                    for (int k = prev + 1; k < i; ++k) s[k] = curc;
                } else if (prevc == 'R' && curc == 'L') {
                    int l = prev + 1, r = i - 1;
                    while (l < r) { s[l++] = 'R'; s[r--] = 'L'; }
                }
                prev = i;
                prevc = curc;
            }
        }
        return s;
    }
};
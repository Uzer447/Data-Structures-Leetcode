#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDifference(string s) {
        int cnt[26] = {};
        for (char c : s) ++cnt[c - 'a'];
        int mx = -1, mn = 101;
        for (int f : cnt) {
            if (!f) continue;
            if (f & 1) mx = max(mx, f);
            else mn = min(mn, f);
        }
        return mx - mn;
    }
};
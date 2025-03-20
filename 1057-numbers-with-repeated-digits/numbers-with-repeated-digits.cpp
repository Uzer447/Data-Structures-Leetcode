#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        int len = s.size(), total = 0;
        for (int i = 1; i < len; i++){
            int count = 9;
            for (int j = 1; j < i; j++) count *= (10 - j);
            total += count;
        }
        unordered_set<int> used;
        for (int i = 0; i < len; i++){
            int digit = s[i] - '0';
            for (int d = (i == 0 ? 1 : 0); d < digit; d++){
                if(used.count(d)) continue;
                int avail = 10 - (i + 1), perms = 1;
                for (int k = 0; k < len - i - 1; k++){
                    perms *= (avail - k);
                }
                total += perms;
            }
            if(used.count(digit)) break;
            used.insert(digit);
            if(i == len - 1) total++;
        }
        return n - total;
    }
};
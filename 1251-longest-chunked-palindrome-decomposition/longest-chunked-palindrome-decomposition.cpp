#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestDecomposition(string text) {
        int n = text.size();
        int i = 0, j = n, res = 0;
        while(i < j) {
            for (int l = 1; l <= j - i; l++) {
                if(text.compare(i, l, text, j - l, l) == 0) {
                    res += (i + l == j ? 1 : 2);
                    i += l;
                    j -= l;
                    break;
                }
            }
        }
        return res;
    }
};
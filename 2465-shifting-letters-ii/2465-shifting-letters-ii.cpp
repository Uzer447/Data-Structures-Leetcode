#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n + 1, 0);
        for (auto& shift : shifts) {
            int start = shift[0], end = shift[1], dir = shift[2];
            int delta = dir == 1 ? 1 : -1;
            diff[start] += delta;
            diff[end + 1] -= delta;
        }
        int total = 0;
        for (int i = 0; i < n; ++i) {
            total += diff[i];
            int shift_amount = ((total % 26) + 26) % 26;
            s[i] = 'a' + (s[i] - 'a' + shift_amount) % 26;
        }
        return s;
    }
};
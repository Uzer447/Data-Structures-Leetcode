#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.size(), maxLen = min(7, n / k);
        vector<int> freq(26);
        for (char c : s) ++freq[c - 'a'];
        vector<char> letters;
        for (char c = 'z'; c >= 'a'; --c) if (freq[c - 'a'] >= k) letters.push_back(c);
        if (letters.empty()) return "";
        
        vector<vector<int>> nxt(n + 2, vector<int>(26, n));
        for (int i = n - 1; i >= 0; --i) {
            nxt[i] = nxt[i + 1];
            nxt[i][s[i] - 'a'] = i;
        }
        
        auto ok = [&](const string& t) {
            int pos = 0;
            for (int rep = 0; rep < k; ++rep) {
                for (char c : t) {
                    if (pos >= n) return false;
                    pos = nxt[pos][c - 'a'];
                    if (pos == n) return false;
                    ++pos;
                }
            }
            return true;
        };
        
        vector<int> limit(26);
        for (int i = 0; i < 26; ++i) limit[i] = freq[i] / k;
        
        string cur, ans;
        vector<int> used(26);
        function<bool(int,int)> dfs = [&](int want, int depth) {
            if (!ok(cur)) return false;
            if (depth == want) { ans = cur; return true; }
            for (char c : letters) {
                int idx = c - 'a';
                if (used[idx] == limit[idx]) continue;
                ++used[idx]; cur.push_back(c);
                if (dfs(want, depth + 1)) return true;
                cur.pop_back(); --used[idx];
            }
            return false;
        };
        
        for (int len = maxLen; len >= 1; --len) if (dfs(len, 0)) return ans;
        return "";
    }
};
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
        return dp(0, 0, s, p, memo);
    }
    bool dp(int i, int j, string& s, string& p, vector<vector<int>>& memo) {
        if (memo[i][j] != -1)
            return memo[i][j];
        int m = s.size(), n = p.size();
        bool ans;
        if (j == n) {
            ans = (i == m);
        } else {
            bool first_match = (i < m && (p[j] == s[i] || p[j] == '.'));
            if (j + 1 < n && p[j + 1] == '*') {
                ans = dp(i, j + 2, s, p, memo) ||
                      (first_match && dp(i + 1, j, s, p, memo));
            } else {
                ans = first_match && dp(i + 1, j + 1, s, p, memo);
            }
        }
        memo[i][j] = ans;
        return ans;
    }
};
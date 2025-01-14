class Solution {
public:
    string s1, s2;
    int dp[31][31][31];
    bool dfs(int i, int j, int len) {
        if (dp[i][j][len] != -1) return dp[i][j][len];
        if (s1.substr(i, len) == s2.substr(j, len)) return dp[i][j][len] = 1;
        string a = s1.substr(i, len), b = s2.substr(j, len);
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if (a != b) return dp[i][j][len] = 0;
        for (int k = 1; k < len; ++k) {
            if (dfs(i, j, k) && dfs(i + k, j + k, len - k)) return dp[i][j][len] = 1;
            if (dfs(i, j + len - k, k) && dfs(i + k, j, len - k)) return dp[i][j][len] =1;
        }
        return dp[i][j][len] = 0;
    }
    bool isScramble(string s1_, string s2_) {
        s1 = s1_;
        s2 = s2_;
        int n = s1.length();
        memset(dp, -1, sizeof(dp));
        return dfs(0, 0, n);
    }
};
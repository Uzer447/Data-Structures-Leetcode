class Solution {
public:
    int strangePrinter(string s) {
        string t;
        int n = s.size();
        if(n == 0) return 0;
        t += s[0];
        for(int i = 1; i < n; ++i)
            if(s[i] != s[i-1]) t += s[i];
        n = t.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for(int i = n - 1; i >= 0; --i) {
            dp[i][i] = 1;
            for(int j = i + 1; j < n; ++j) {
                dp[i][j] = dp[i + 1][j] + 1;
                for(int k = i + 1; k <= j; ++k)
                    if(t[k] == t[i])
                        dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k][j]);
            }
        }
        return dp[0][n - 1];
    }
};
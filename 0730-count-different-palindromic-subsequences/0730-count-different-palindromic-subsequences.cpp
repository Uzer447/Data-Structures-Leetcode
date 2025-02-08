class Solution {
public:
    int countPalindromicSubsequences(string s) {
        const int mod = 1e9 + 7;
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        vector<vector<int>> next_pos(n, vector<int>(4, -1));
        vector<vector<int>> prev_pos(n, vector<int>(4, -1));
        vector<int> pos(4, -1);
        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            for (int k = 0; k < 4; ++k)
                prev_pos[i][k] = pos[k];
            pos[c] = i;
        }
        pos.assign(4, -1);
        for (int i = n - 1; i >= 0; --i) {
            int c = s[i] - 'a';
            for (int k = 0; k < 4; ++k)
                next_pos[i][k] = pos[k];
            pos[c] = i;
        }
        for (int i = 0; i < n; ++i)
            dp[i][i] = 1;
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i + len <= n; ++i) {
                int j = i + len - 1;
                if (s[i] != s[j]) {
                    dp[i][j] =
                        ((dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1]) %
                             mod +
                         mod) %
                        mod;
                } else {
                    int c = s[i] - 'a';
                    int l = next_pos[i][c], r = prev_pos[j][c];
                    if (l == -1 || l > r) {
                        dp[i][j] = (2LL * dp[i + 1][j - 1] + 2) % mod;
                    } else if (l == r) {
                        dp[i][j] = (2LL * dp[i + 1][j - 1] + 1) % mod;
                    } else {
                        dp[i][j] =
                            ((2LL * dp[i + 1][j - 1] - dp[l + 1][r - 1]) % mod +
                             mod) %
                            mod;
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};
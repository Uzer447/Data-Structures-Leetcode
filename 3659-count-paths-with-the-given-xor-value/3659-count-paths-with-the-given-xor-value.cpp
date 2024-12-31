class Solution {
public:
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        const int MOD = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(16, 0)));
        dp[0][0][grid[0][0]] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;
                for (int x = 0; x < 16; ++x) {
                    int current_xor = x ^ grid[i][j];
                    int ways = 0;
                    if (i > 0) {
                        ways = (ways + dp[i - 1][j][x]) % MOD;
                    }
                    if (j > 0) {
                        ways = (ways + dp[i][j - 1][x]) % MOD;
                    }
                    dp[i][j][current_xor] = (dp[i][j][current_xor] + ways) % MOD;
                }
            }
        }
        return dp[m - 1][n - 1][k];
    }
};
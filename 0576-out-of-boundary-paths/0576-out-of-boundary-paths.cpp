class Solution {
public:
    int mod = 1e9 + 7;
    int solve(int m, int n, int r, int c, int maxMove,
              vector<vector<vector<int>>>& dp) {

        if (r >= m || c >= n || r < 0 || c < 0)
            return 1;
        if (maxMove <= 0)
            return 0;

        if (dp[r][c][maxMove] != -1)
            return dp[r][c][maxMove];

        int left = solve(m, n, r, c - 1, maxMove - 1, dp) % mod;
        int right = solve(m, n, r, c + 1, maxMove - 1, dp) % mod;
        int up = solve(m, n, r - 1, c, maxMove - 1, dp) % mod;
        int down = solve(m, n, r + 1, c, maxMove - 1, dp) % mod;

        return dp[r][c][maxMove] =
                   (((left % mod + right % mod) % mod + up % mod) % mod +
                    down % mod) %
                   mod;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(
            m + 1, vector<vector<int>>(n + 1, vector<int>(maxMove + 1, -1)));
        return solve(m, n, startRow, startColumn, maxMove, dp);
    }
};
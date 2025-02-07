class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        function<int(int, int)> dfs = [&](int i, int j) {
            if(dp[i][j]) return dp[i][j];
            int max_len = 1;
            vector<int> dirs = {-1, 0, 1, 0, -1};
            for(int d = 0; d < 4; ++d) {
                int x = i + dirs[d], y = j + dirs[d+1];
                if(x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j]) {
                    max_len = max(max_len, 1 + dfs(x, y));
                }
            }
            dp[i][j] = max_len;
            return max_len;
        };
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                res = max(res, dfs(i, j));
        return res;
    }
};
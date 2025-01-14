class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        if (!m) return 0;
        n = matrix[0].size();
        this->matrix = matrix;
        cache = vector<vector<int>>(m, vector<int>(n, 0));
        int ans = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                ans = max(ans, dfs(i, j));
        return ans;
    }
private:
    int m, n;
    vector<vector<int>> matrix;
    vector<vector<int>> cache;
    int dirs[5] = {-1, 0, 1, 0, -1};
    int dfs(int i, int j) {
        if (cache[i][j]) return cache[i][j];
        int max_len = 1;
        for (int k = 0; k < 4; ++k) {
            int x = i + dirs[k], y = j + dirs[k+1];
            if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j]) {
                int len = 1 + dfs(x, y);
                max_len = max(max_len, len);
            }
        }
        cache[i][j] = max_len;
        return max_len;
    }
};
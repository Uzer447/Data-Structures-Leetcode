class Solution {
public:
    int n;
    vector<vector<int>> grid;
    int memo[50][50][50];
    int dp(int r1, int c1, int c2) {
        int r2 = r1 + c1 - c2;
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n ||
            grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return -1e9;
        if (r1 == n - 1 && c1 == n - 1)
            return grid[r1][c1];
        if (memo[r1][c1][c2] != -1e9)
            return memo[r1][c1][c2];
        int ans = grid[r1][c1];
        if (c1 != c2)
            ans += grid[r2][c2];
        int temp = max(max(dp(r1 + 1, c1, c2), dp(r1, c1 + 1, c2)),
                       max(dp(r1 + 1, c1, c2 + 1), dp(r1, c1 + 1, c2 + 1)));
        ans += temp;
        memo[r1][c1][c2] = ans;
        return ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        this->grid = grid;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                fill(memo[i][j], memo[i][j] + n, -1e9);
        int res = dp(0, 0, 0);
        return max(0, res);
    }
};
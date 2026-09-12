class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& grid,
             vector<vector<int>>& vis, int n, int m) {
        vis[row][col] = 1;
        int dr[] = {-1, 0, +1, 0};
        int dc[] = {0, -1, 0, +1};

        for (int i = 0; i < 4; i++) {
            int nrow = row + dr[i];
            int ncol = col + dc[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                !vis[nrow][ncol] && grid[nrow][ncol] == '1') {
                dfs(nrow, ncol, grid, vis, n, m);
            }
        }
    }

    void bfs(int row, int col, vector<vector<char>>& grid,
             vector<vector<int>>& vis, int n, int m) {
        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = 1;
        int dr[] = {-1, 0, +1, 0};
        int dc[] = {0, -1, 0, +1};
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nrow = r + dr[i];
                int ncol = c + dc[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    !vis[nrow][ncol] && grid[nrow][ncol] == '1') {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 0 && grid[i][j] == '1') {
                    cnt++;
                    bfs(i, j, grid, vis, n, m);
                }
            }
        }
        return cnt;
    }
};
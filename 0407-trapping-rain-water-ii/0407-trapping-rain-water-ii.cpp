class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        if (m <= 2) return 0;
        int n = heightMap[0].size();
        if (n <= 2) return 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        struct Cell {
            int h, x, y;
            Cell(int height, int i, int j) : h(height), x(i), y(j) {}
        };
        auto cmp = [](const Cell& a, const Cell& b) { return a.h > b.h; };
        priority_queue<Cell, vector<Cell>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < m; ++i) {
            pq.emplace(heightMap[i][0], i, 0);
            pq.emplace(heightMap[i][n - 1], i, n - 1);
            visited[i][0] = visited[i][n - 1] = true;
        }
        for (int j = 1; j < n - 1; ++j) {
            pq.emplace(heightMap[0][j], 0, j);
            pq.emplace(heightMap[m - 1][j], m - 1, j);
            visited[0][j] = visited[m - 1][j] = true;
        }
        int res = 0, dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        while (!pq.empty()) {
            auto cell = pq.top(); pq.pop();
            for (auto& d : dirs) {
                int x = cell.x + d[0], y = cell.y + d[1];
                if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y]) {
                    visited[x][y] = true;
                    res += max(0, cell.h - heightMap[x][y]);
                    pq.emplace(max(heightMap[x][y], cell.h), x, y);
                }
            }
        }
        return res;
    }
};
class Solution {
public:
    int containVirus(vector<vector<int>>& isInfected) {
        int m = isInfected.size(), n = isInfected[0].size(), res = 0;
        vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
        while (true) {
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            vector<vector<pair<int,int>>> regions;
            vector<set<int>> frontiers;
            vector<int> walls;
            for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) {
                if (isInfected[i][j] == 1 && !visited[i][j]) {
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    visited[i][j] = true;
                    regions.push_back({});
                    frontiers.push_back({});
                    walls.push_back(0);
                    while (!q.empty()) {
                        auto [x,y] = q.front(); q.pop();
                        regions.back().push_back({x,y});
                        for (auto& d : dirs) {
                            int nx = x + d[0], ny = y + d[1];
                            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                                if (isInfected[nx][ny] == 0) {
                                    walls.back()++;
                                    frontiers.back().insert(nx*n + ny);
                                } else if (isInfected[nx][ny] == 1 && !visited[nx][ny]) {
                                    visited[nx][ny] = true;
                                    q.push({nx, ny});
                                }
                            }
                        }
                    }
                }
            }
            if (regions.empty()) break;
            int idx = 0;
            for (int i = 1; i < frontiers.size(); ++i)
                if (frontiers[i].size() > frontiers[idx].size()) idx = i;
            res += walls[idx];
            for (auto& [x, y] : regions[idx]) isInfected[x][y] = 2;
            for (int i = 0; i < regions.size(); ++i) {
                if (i == idx) continue;
                for (int code : frontiers[i]) {
                    int x = code / n, y = code % n;
                    if (isInfected[x][y] == 0) isInfected[x][y] = 3;
                }
            }
            bool done = true;
            for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) {
                if (isInfected[i][j] == 3) isInfected[i][j] = 1, done = false;
                else if (isInfected[i][j] == 1) done = false;
            }
            if (done) break;
        }
        return res;
    }
};
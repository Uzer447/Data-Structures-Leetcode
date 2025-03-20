#include <queue>
#include <tuple>
#include <vector>
using namespace std;
class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size(), allKeys = 0, startX = 0,
            startY = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                char c = grid[i][j];
                if (c == '@') {
                    startX = i;
                    startY = j;
                } else if (c >= 'a' && c <= 'f')
                    allKeys |= (1 << (c - 'a'));
            }
        vector<vector<vector<bool>>> vis(
            m, vector<vector<bool>>(n, vector<bool>(1 << 6, false)));
        queue<tuple<int, int, int, int>> q;
        q.push({startX, startY, 0, 0});
        vis[startX][startY][0] = true;
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            auto [x, y, keys, steps] = q.front();
            q.pop();
            if (keys == allKeys)
                return steps;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dirs[i][0], ny = y + dirs[i][1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;
                char c = grid[nx][ny];
                if (c == '#')
                    continue;
                int newKeys = keys;
                if (c >= 'a' && c <= 'f')
                    newKeys |= (1 << (c - 'a'));
                if (c >= 'A' && c <= 'F' && !(keys & (1 << (c - 'A'))))
                    continue;
                if (!vis[nx][ny][newKeys]) {
                    vis[nx][ny][newKeys] = true;
                    q.push({nx, ny, newKeys, steps + 1});
                }
            }
        }
        return -1;
    }
};
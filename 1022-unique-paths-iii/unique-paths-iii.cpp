#include <vector>
#include <functional>
using namespace std;
class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), total = 0, si = 0, sj = 0;
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != -1) total++;
                if (grid[i][j] == 1) { si = i; sj = j; }
            }
        int ans = 0;
        function<void(int, int, int)> dfs = [&](int i, int j, int count) {
            if (grid[i][j] == 2) {
                if (count == total) ans++;
                return;
            }
            int temp = grid[i][j];
            grid[i][j] = -1;
            int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
            for (auto &d: dir) {
                int ni = i + d[0], nj = j + d[1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] != -1)
                    dfs(ni, nj, count + 1);
            }
            grid[i][j] = temp;
        };
        dfs(si, sj, 1);
        return ans;
    }
};
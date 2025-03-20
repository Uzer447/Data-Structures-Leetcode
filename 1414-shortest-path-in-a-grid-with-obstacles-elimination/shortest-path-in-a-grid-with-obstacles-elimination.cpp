#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        if(k >= m + n - 3) return m + n - 2;
        vector<vector<vector<bool>>> vis(m, vector<vector<bool>>(n, vector<bool>(k+1, false)));
        queue<tuple<int,int,int,int>> q;
        q.push({0,0,0,0});
        vis[0][0][0] = true;
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            auto [x, y, steps, used] = q.front();
            q.pop();
            if(x == m - 1 && y == n - 1) return steps;
            for(auto &d: dirs){
                int nx = x + d[0], ny = y + d[1];
                if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                int nused = used + grid[nx][ny];
                if(nused <= k && !vis[nx][ny][nused]){
                    vis[nx][ny][nused] = true;
                    q.push({nx, ny, steps + 1, nused});
                }
            }
        }
        return -1;
    }
};
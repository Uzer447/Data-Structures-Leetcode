#include <vector>
#include <queue>
#include <tuple>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if(heightMap.empty() || heightMap[0].empty())
            return 0;
        int m = heightMap.size(), n = heightMap[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        typedef tuple<int, int, int> T;
        priority_queue<T, vector<T>, greater<T>> pq;
        for(int i = 0; i < m; ++i) {
            pq.push({heightMap[i][0], i, 0});
            visited[i][0] = true;
            pq.push({heightMap[i][n-1], i, n-1});
            visited[i][n-1] = true;
        }
        for(int j = 1; j < n-1; ++j) {
            pq.push({heightMap[0][j], 0, j});
            visited[0][j] = true;
            pq.push({heightMap[m-1][j], m-1, j});
            visited[m-1][j] = true;
        }
        int res = 0;
        int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        while(!pq.empty()) {
            auto [height, x, y] = pq.top();
            pq.pop();
            for(auto& dir : dirs) {
                int nx = x + dir[0], ny = y + dir[1];
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    res += max(0, height - heightMap[nx][ny]);
                    pq.push({max(heightMap[nx][ny], height), nx, ny});
                }
            }
        }
        return res;
    }
};
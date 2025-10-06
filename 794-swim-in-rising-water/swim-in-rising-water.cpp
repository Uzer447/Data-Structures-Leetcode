typedef tuple<int, int, int> ti;
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        vector<int> dir = {-1, 0, 1, 0, -1};
        int n=grid.size();

        vector<vector<int>> dist(n, vector<int>(n, 1e9)); 
        dist[0][0] = grid[0][0]; 

        set<ti> s; 
        s.insert({grid[0][0], 0, 0}); 

        while (s.size()) {
            auto top = *(s.begin()); 
            auto [curTime, i, j] = top;
            s.erase(top);
            if (i==n-1 and j==n-1) return dist[i][j];
            for (int k=0; k<4; k++) {
                int x=i+dir[k], y=j+dir[k+1];
                if (x>=0 and y>=0 and x<n and y<n) { 
                    if (grid[x][y] <= grid[i][j] and curTime < dist[x][y]) {
                        if (dist[x][y] != 1e9) s.erase({dist[x][y], x, y}); 
                        dist[x][y] = curTime; 
                        s.insert({dist[x][y], x, y}); 
                    }
                    else if (dist[x][y] == 1e9) {
                        dist[x][y] = max(grid[x][y], curTime);
                        s.insert({dist[x][y], x, y});
                    }
                }

            }

        }

        return dist.back().back();
    }
};
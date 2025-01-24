class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int j=0;j<m;j++)
        {
            if(!vis[0][j] && grid[0][j]==1)
            {
                q.push({0,j});
                vis[0][j]=1;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(!vis[i][0] && grid[i][0]==1)
            {
                q.push({i,0});
                vis[i][0]=1;
            }
        }
        for(int j=m-1;j>=0;j--)
        {
            if(!vis[n-1][j] && grid[n-1][j]==1)
            {
                q.push({n-1,j});
                vis[n-1][j]=1;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(!vis[i][m-1] && grid[i][m-1]==1)
            {
                q.push({i,m-1});
                vis[i][m-1]=1;
            }
        }
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nrow = row + delrow[i];
                    int ncol = col + delcol[i];
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol]!=1
                        && grid[nrow][ncol] == 1) {
                        q.push({nrow, ncol});
                        vis[nrow][ncol] = 1;
                    }
                }
            }
        }
        int land=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && vis[i][j]==0)
                {
                    land++;
                }
            }
        }
        return land;
    }
};
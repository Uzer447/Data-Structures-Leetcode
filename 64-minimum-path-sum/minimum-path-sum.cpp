class Solution {
public:
    int func(int r,int c,int n,int m,vector<vector<int>> &grid)
    {
        if(r<0 || c<0) return 1e9;
        if(r==0 && c==0)
            return grid[r][c];
        int up=func(r-1,c,n,m,grid);
        int left=func(r,c-1,n,m,grid);
        return min(up,left)+grid[r][c];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n-1;i++)
        {
            for(int j=0;j<=m-1;j++)
            {
                if(i==0 && j==0)
                {
                    dp[i][j]=grid[i][j];
                    continue;
                }
                int up=grid[i][j];
                int left=grid[i][j];
                if(i-1>=0) up+=dp[i-1][j];
                else up=1e9;
                if(j-1>=0) left+=dp[i][j-1];
                else left=1e9;
                dp[i][j]=min(up,left);
            }
        }
        return dp[n-1][m-1];
    }

};
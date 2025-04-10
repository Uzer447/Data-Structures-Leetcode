class Solution {
public:
    int MOD=1e9+7;
    int func(int row,int col,vector<vector<int>> &grid,int sum,int k,int n,int m,vector<vector<vector<int>>> &dp)
    {
        if(row>=n || col>=m)
        {
            return 0;
        }
        sum=(sum+grid[row][col])%k;
        if(row==n-1 && col==m-1)
        {
            if(sum%k==0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        if(dp[row][col][sum]!=-1)
            return dp[row][col][sum];
        int down=func(row+1,col,grid,sum,k,n,m,dp);
        int right=func(row,col+1,grid,sum,k,n,m,dp);
        return dp[row][col][sum]=((down+right)%MOD);

    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k,-1)));
        return func(0,0,grid,0,k,n,m,dp);
    }
};
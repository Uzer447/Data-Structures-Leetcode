class Solution {
public:
    int func(int i, int j, vector<vector<int>> &mat,int n,int m,vector<vector<int>> &dp)
    {
        if(i==n-1 && j==m-1)
        return mat[i][j];
        if(dp[i][j]!=-1)
        return dp[i][j];
        if(i==n-1)
            return mat[i][j]+((dp[i][j+1]!=-1)?dp[i][j+1]:func(i,j+1,mat,n,m,dp));
        if(j==m-1)
            return mat[i][j]+((dp[i+1][j]!=-1)?dp[i+1][j]:func(i+1,j,mat,n,m,dp));
        return dp[i][j]=mat[i][j]+min(func(i+1,j,mat,n,m,dp),func(i,j+1,mat,n,m,dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        ans=func(0,0,grid,n,m,dp);
        return ans;
    }
};
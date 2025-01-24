class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int j=0;j<n;j++)
        {
            dp[0][j]=matrix[0][j];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int ld=matrix[i][j];
                int rd=matrix[i][j];
                int s=matrix[i][j]+dp[i-1][j];
                if(j-1>=0) ld+=dp[i-1][j-1];
                else ld+=1e8;
                if(j+1<n) rd+=dp[i-1][j+1];
                else rd+=1e8;
                dp[i][j]=min(s,min(ld,rd));
            }
        }
        int maxi=1e8;
        for(int j=0;j<n;j++)
        {
            maxi=min(maxi,dp[n-1][j]);
        }
        return maxi;
    }
};
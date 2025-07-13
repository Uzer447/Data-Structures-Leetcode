class Solution {
public:
    int func(int i,int j,int n,int m,string s,string t,vector<vector<int>> &dp)
    {
        if(i>=n || j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j])
        {
            return dp[i][j]=1+func(i+1,j+1,n,m,s,t,dp);
        }
        return dp[i][j]=max(func(i+1,j,n,m,s,t,dp),func(i,j+1,n,m,s,t,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(text1[i]==text2[j])
                {
                    dp[i][j]=1+dp[i+1][j+1];
                }
                else
                {
                    dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};
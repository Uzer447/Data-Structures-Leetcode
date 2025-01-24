class Solution {
public:
    int stepsneeded(int i,int n,vector<int> &dp)
    {
        if(i==n)
        {
            return 1;
        }
        if(i>n)
        {
            return 0;
        }
        if(dp[i]!=-1)
        return dp[i];
        dp[i]=stepsneeded(i+1,n,dp)+stepsneeded(i+2,n,dp);
        return dp[i];
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return stepsneeded(0,n,dp);
    }
};
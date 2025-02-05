class Solution {
public:
    int maxdom(int n, int sum, vector<int>&arr,vector<vector<int>>&dp)
    {
        if(sum==0)return 1;
        if(n<=0||sum<0)return 0;
        if(dp[n][sum]!=-1)return dp[n][sum];

        if(arr[n-1]>sum)
        {
            return dp[n][sum]=maxdom(n-1,sum,arr,dp);
        }

        return dp[n][sum]=maxdom(n-1,sum,arr,dp)+maxdom(n,sum-arr[n-1],arr,dp);
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return maxdom(n,amount,coins,dp);
    }
};
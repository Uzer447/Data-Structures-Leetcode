class Solution {
public:
    int func(int ind,int n,int amt,vector<int> &coins)
    {
        if(ind==n-1)
        {
            if(amt%coins[ind]==0)
            {
                return amt/coins[ind];
            }
            else
                return 1e9;
        }
        int take=1e9;
        int nottake=func(ind+1,n,amt,coins);
        if(amt>=coins[ind])
        {
            take=1+func(ind,n,amt-coins[ind],coins);
        }
        return min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,0));
        for(int i=0;i<=amount;i++)
        {
            if(i%coins[n-1]==0)
            {
                dp[n-1][i]=i/coins[n-1];
            }
            else
                dp[n-1][i]=1e9;
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int amt=0;amt<=amount;amt++)
            {
                int take=1e9;
                int nottake=dp[i+1][amt];
                if(amt>=coins[i])
                {
                    take=1+dp[i][amt-coins[i]];
                }
                dp[i][amt]=min(take,nottake);
            }
        }
        if(dp[0][amount]==1e9) return -1;
        return dp[0][amount];
        int ans=func(0,n,amount,coins);
        if(ans==1e9)
            return -1;
        return ans;

    }
};
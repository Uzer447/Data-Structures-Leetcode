class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,1e9);
        dp[0]=0;
        for(int amt=1;amt<=amount;amt++)
        {
            for(int i=0;i<coins.size();i++)
            {
                if(amt-coins[i]>=0)
                dp[amt]=min(dp[amt],1+dp[amt-coins[i]]);
            }
        }
        if(dp[amount]==1e9)
            dp[amount]=-1;
        return dp[amount];
    }
};
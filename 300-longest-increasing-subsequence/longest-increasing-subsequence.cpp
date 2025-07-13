class Solution {
public:
    int func(int ind,int n,int lastele,vector<int> &nums)
    {
        if(ind>=n)
            return 0;
        int take=0;
        int nottake=func(ind+1,n,lastele,nums);
        if(lastele==-1 || nums[ind]>nums[lastele])
        {
            take=1+func(ind+1,n,ind,nums);
        }
        return max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int prevind=-1;prevind<=i-1;prevind++)
            {
                int take=0;
                int nottake=dp[i+1][prevind+1];
                if(prevind==-1 || nums[i]>nums[prevind])
                {
                    take=1+dp[i+1][i+1];
                }
                dp[i][prevind+1]=max(take,nottake);
            }
        }
        return dp[0][0];
    }
};
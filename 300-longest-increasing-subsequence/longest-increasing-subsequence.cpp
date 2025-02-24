class Solution {
public:
    int func(int ind,int prevind,vector<int> &nums,vector<vector<int>> &dp)
    {
        if(ind==nums.size())
        {
            return 0;
        }
        if(dp[ind][prevind+1]!=-1)
        return dp[ind][prevind+1];
        int take=0;
        int nottake=func(ind+1,prevind,nums,dp);
        if(prevind==-1 || nums[ind]>nums[prevind])
        {
            take=1+func(ind+1,ind,nums,dp);
        }
        return dp[ind][prevind+1]=max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return func(0,-1,nums,dp);
    }
};
class Solution {
public:
    bool func(int ind,int target,vector<int> &nums,int n,vector<vector<int>> &dp)
    {
        if(ind==n-1)
        {
            return dp[ind][target]=(nums[ind]==target);
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        bool nottake=func(ind+1,target,nums,n,dp);
        bool take;
        if(nums[ind]<=target)
        {
            take=func(ind+1,target-nums[ind],nums,n,dp);
        }
        return dp[ind][target]=nottake|take;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1) return false;
        vector<vector<int>> dp(n+1,vector<int>(sum/2+1,-1));
        return func(0,sum/2,nums,n,dp);
    }
};
class Solution {
public:
    bool func(int ind,int n,vector<int> &nums,int target)
    {
        if(target==0)
            return true;
        if(ind==n-1)
        {
            if(target==nums[ind])
            {
                return true;
            }
            return false;
        }
        bool take=true;
        bool nottake=func(ind+1,n,nums,target);
        if(nums[ind]<=target)
        {
            take=func(ind+1,n,nums,target-nums[ind]);
        }
        return take|nottake;
    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int n=nums.size();
        if(sum%2!=0) return false;
        sum/=2;
        vector<vector<bool>> dp(n+1,vector<bool>(sum+1));
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=true;
        }
        for(int i=0;i<=sum;i++)
        {
            if(i==nums[n-1])dp[n-1][sum]=true;
            else dp[n-1][sum]=false;
        }
        for(int ind=n-2;ind>=0;ind--)
        {
            for(int target=1;target<=sum;target++)
            {
                bool take=false;
                bool nottake=dp[ind+1][target];
                if(target>=nums[ind])
                {
                    take=dp[ind+1][target-nums[ind]];
                }
                dp[ind][target]=take|nottake;
            }
        }
        return dp[0][sum];
        return func(0,n,nums,sum/2);
    }
};
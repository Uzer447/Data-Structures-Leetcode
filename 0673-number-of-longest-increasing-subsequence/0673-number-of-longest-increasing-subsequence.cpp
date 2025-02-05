class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), cnt(n, 1);
        int maxi = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if(dp[i]<1+dp[j])
                    {
                        dp[i]=dp[j]+1;
                        cnt[i]=cnt[j];
                    }
                    else if(dp[i]==1+dp[j])
                    {
                        dp[i]=dp[j]+1;
                        cnt[i]+=cnt[j];
                    }
                }
            }
            maxi = max(dp[i], maxi);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(dp[i]==maxi)
            {
                ans+=cnt[i];
            }
        }
        return ans;
    }
};
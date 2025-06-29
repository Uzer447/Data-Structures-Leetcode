class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int n=nums.size();
        int MOD=1e9+7;
        int left=0;
        int right=n-1;
        vector<int> powers(n);
        powers[0]=1;
        for(int i=1;i<n;i++)
        {
            powers[i]=(powers[i-1]*2)%MOD;
        }
        while(left<=right)
        {
            if(nums[left]+nums[right]<=target)
            {
                ans=(ans+powers[right-left])%MOD;
                left++;
            }
            else
            {
                right--;
            }
        }
        return ans;
    }
};
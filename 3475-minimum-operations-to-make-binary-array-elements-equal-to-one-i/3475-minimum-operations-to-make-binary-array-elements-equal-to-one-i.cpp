class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt1=0;
        int n=nums.size();
        int ans=0;
        for(int i=0;i+2<n;i++)
        {
            if(nums[i]==0)
            {
                ans++;
                nums[i]=1;
                nums[i+1]=1-nums[i+1];
                nums[i+2]=1-nums[i+2];
            }
        }
        for(auto &it:nums)
        {
            if(it==0)
                return -1;
        }
        return ans;
    }
};
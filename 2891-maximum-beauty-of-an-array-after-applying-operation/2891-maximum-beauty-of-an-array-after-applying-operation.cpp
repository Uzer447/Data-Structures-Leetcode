class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int ind=upper_bound(nums.begin(),nums.end(),nums[i]+2*k)-nums.begin();
            ans=max(ans,ind-i+1);
        }
        return ans-1;
    }
};
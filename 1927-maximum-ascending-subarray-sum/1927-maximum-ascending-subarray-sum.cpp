class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxans=INT_MIN;
        int curr=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++)
        {
            if(nums[i+1]>nums[i])
            {
                curr+=nums[i];
            }
            else
            {
                curr+=nums[i];
                maxans=max(maxans,curr);
                curr=0;
            }
        }

        maxans=max(maxans,curr+nums[n-1]);
        return maxans;
        
    }
};
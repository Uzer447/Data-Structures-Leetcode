class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(nums[0+1]!=nums[0])
        return nums[0];
        if(nums[n-1-1]!=nums[n-1])
        return nums[n-1];
        int low=1;
        int high=n-2;
        while(low<=high)
        {
            int mid=(low+high)>>1;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])
            return nums[mid];
            if((mid%2==0 && nums[mid+1]==nums[mid]) || (mid%2==1 && nums[mid-1]==nums[mid]))
            low=mid+1;
            if((mid%2==0 && nums[mid-1]==nums[mid]) || (mid%2==1 && nums[mid+1]==nums[mid]))
            high=mid-1;
        }
        return -1;
    }
};
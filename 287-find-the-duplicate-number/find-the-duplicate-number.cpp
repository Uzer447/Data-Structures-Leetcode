class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0];
        int fast=nums[0];
        do
        {
            slow=nums[slow];
            fast=nums[nums[fast]];
        }
        while(fast!=slow);
        fast=nums[0];
        while(fast!=slow)
        {
            fast=nums[fast];
            slow=nums[slow];
        }
        return fast;
    }
};
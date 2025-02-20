class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int p1=nums[0];
        int p2=nums[0];
        int res=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            int temp=max(nums[i],max(p1*nums[i],p2*nums[i]));
            p2=min(nums[i],min(p1*nums[i],p2*nums[i]));
            p1=temp;
            res=max(res,p1);
        }
        return res;
    }
};
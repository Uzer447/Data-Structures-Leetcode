class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxprod = 1;
        int minprod = 1;
        int res = INT_MIN;
        for (int i = 0; i < n; i++) {
            int temp = max(nums[i], max(maxprod * nums[i], minprod * nums[i]));
            minprod = min(nums[i], min(maxprod * nums[i], minprod * nums[i]));
            maxprod = temp;
            res = max(res, maxprod);
        }
        return res;
    }
};
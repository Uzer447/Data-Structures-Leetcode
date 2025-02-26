class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int max_current = nums[0], max_sum = nums[0], min_current = nums[0],
            min_sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            max_current = max(max_current + nums[i], nums[i]);
            max_sum = max(max_sum, max_current);
            min_current = min(min_current + nums[i], nums[i]);
            min_sum = min(min_sum, min_current);
        }
        return max(max_sum, abs(min_sum));
    }
};
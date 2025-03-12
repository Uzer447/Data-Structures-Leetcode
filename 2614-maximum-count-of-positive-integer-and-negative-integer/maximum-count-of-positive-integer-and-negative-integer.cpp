class Solution {
public:
    int maximumCount(vector<int> &nums) {
        int positiveCount = nums.size() - (upper_bound(nums.begin(),nums.end(),0)-nums.begin());
        int negativeCount = lower_bound(nums.begin(),nums.end(),0)-nums.begin();
        return max(positiveCount, negativeCount);
    }
};
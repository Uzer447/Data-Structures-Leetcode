class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 1, mn = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] - mn > k) {
                ++ans;
                mn = nums[i];
            }
        }
        return ans;
    }
};
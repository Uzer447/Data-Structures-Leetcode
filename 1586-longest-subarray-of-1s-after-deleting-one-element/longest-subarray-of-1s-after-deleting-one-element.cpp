class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, zeros = 0, best = 0;
        for (int right = 0; right < nums.size(); ++right) {
            if (!nums[right]) ++zeros;
            while (zeros > 1) {
                if (!nums[left]) --zeros;
                ++left;
            }
            best = max(best, right - left + 1);
        }
        return best - 1;
    }
};
class Solution {
public:
    bool canRob(const vector<int>& nums, int k, int cap) {
        int count = 0, n = nums.size();
        for (int i = 0; i < n;) {
            if (nums[i] <= cap) {
                count++;
                i += 2;
            } else {
                i++;
            }
        }
        return count >= k;
    }
    int minCapability(vector<int>& nums, int k) {
        int low = *min_element(nums.begin(), nums.end()),
            high = *max_element(nums.begin(), nums.end());
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (canRob(nums, k, mid))
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};
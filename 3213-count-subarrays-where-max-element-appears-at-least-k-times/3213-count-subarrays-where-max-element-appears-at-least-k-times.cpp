class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), mx = *max_element(nums.begin(), nums.end());
        int left = 0, cnt = 0, totalMx = 0;
        for (int v : nums) if (v == mx) ++totalMx;
        if (totalMx < k) return 0;
        long long ans = 0;
        for (int right = 0; right < n; ++right) {
            if (nums[right] == mx) ++cnt;
            while (cnt >= k) {
                ans += n - right;
                if (nums[left] == mx) --cnt;
                ++left;
            }
        }
        return ans;
    }
};
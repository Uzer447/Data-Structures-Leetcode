class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int max_or = 0;
        for (int x : nums) max_or |= x;
        int m = 1 << n;
        vector<int> dp(m);
        int ans = 0;
        for (int mask = 1; mask < m; ++mask) {
            int b = __builtin_ctz(mask);
            dp[mask] = dp[mask ^ (1 << b)] | nums[b];
            if (dp[mask] == max_or) ++ans;
        }
        return ans;
    }
};
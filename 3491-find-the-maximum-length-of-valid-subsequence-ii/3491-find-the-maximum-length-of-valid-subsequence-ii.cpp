class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size(), ans = 1;
        vector<vector<int>> dp(n, vector<int>(k, 0));
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < j; ++i) {
                int r = (nums[i] + nums[j]) % k;
                int len = 2;
                if (dp[i][r]) len = dp[i][r] + 1;
                if (len > dp[j][r]) {
                    dp[j][r] = len;
                    if (len > ans) ans = len;
                }
            }
        }
        return ans;
    }
};
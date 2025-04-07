class Solution {
public:
    bool func(int ind, int target, vector<int>& nums, int n,
              vector<vector<int>>& dp) {
        if (ind == n - 1) {
            return dp[ind][target] = (nums[ind] == target);
        }
        if (dp[ind][target] != -1)
            return dp[ind][target];
        bool nottake = func(ind + 1, target, nums, n, dp);
        bool take;
        if (nums[ind] <= target) {
            take = func(ind + 1, target - nums[ind], nums, n, dp);
        }
        return dp[ind][target] = nottake | take;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1)
            return false;
        int k = sum / 2;
        vector<vector<int>> dp(n + 1, vector<int>(k+1, 0));
        dp[0][0] = (nums[0] <= k);
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }
        for (int ind = 1; ind < n; ind++) {
            for (int target = 1; target <= k; target++) {
                bool nottake = dp[ind - 1][target];
                bool take=false;
                if (nums[ind] <= target) {
                    take = dp[ind - 1][target-nums[ind]];
                }
                dp[ind][target] = nottake || take;
            }
        }
        return dp[n-1][k];
    }
};
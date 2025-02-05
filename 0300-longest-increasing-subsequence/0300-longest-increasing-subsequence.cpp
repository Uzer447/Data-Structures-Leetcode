class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector < vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int prevind = ind-1; prevind >= -1; prevind--) {
                int notTake = 0 + dp[ind + 1][prevind+1];
                int take = INT_MIN;
                if (prevind == -1 || nums[ind] > nums[prevind]) {
                    take = 1 + dp[ind + 1][ind+1];
                }
                dp[ind][prevind+1] = max(take, notTake);
            }
        }
        return dp[0][0];
    }
};
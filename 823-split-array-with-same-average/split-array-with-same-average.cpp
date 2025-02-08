class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size(), s = accumulate(nums.begin(), nums.end(), 0);
        bool possible = false;
        for (int k = 1; k <= n / 2; ++k) {
            if ((s * k) % n == 0) {
                possible = true;
                break;
            }
        }
        if (!possible) return false;
        vector<unordered_set<int>> dp(n / 2 + 1);
        dp[0].insert(0);
        for (int num : nums) {
            for (int k = n / 2; k >= 1; --k) {
                for (int prev : dp[k - 1]) {
                    dp[k].insert(prev + num);
                }
            }
        }
        for (int k = 1; k <= n / 2; ++k) {
            if ((s * k) % n != 0) continue;
            int target = (s * k) / n;
            if (dp[k].count(target)) return true;
        }
        return false;
    }
};
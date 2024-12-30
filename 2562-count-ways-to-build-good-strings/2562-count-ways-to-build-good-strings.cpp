class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int mod = 1e9 + 7;
        std::vector<int> dp(high + 1, 0);
        dp[0] = 1; // Base case: empty string

        for (int i = 1; i <= high; ++i) {
            if (i >= zero) {
                dp[i] = (dp[i] + dp[i - zero]) % mod;
            }
            if (i >= one) {
                dp[i] = (dp[i] + dp[i - one]) % mod;
            }
        }

        int total = 0;
        for (int i = low; i <= high; ++i) {
            total = (total + dp[i]) % mod;
        }

        return total;
    }
};
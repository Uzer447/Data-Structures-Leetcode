class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {

        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        if (n == 0)
            return 1;
        dp[1] = 10;
        for (int i = 2; i <= n; i++) {
            int cnt = 1;
            int mul = 9;
            int j = i;
            while (j != 1) {
                cnt *= mul;
                mul--;
                j--;
            }
            cnt *= 9;
            dp[i] = dp[i - 1] + cnt;
        }
        return dp[n];
    }
};
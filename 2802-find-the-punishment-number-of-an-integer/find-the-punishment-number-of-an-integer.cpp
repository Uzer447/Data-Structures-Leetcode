class Solution {
public:
    bool canPartition(const string& s, int pos, int t,
                      vector<vector<int>>& dp) {
        if (pos == s.size())
            return t == 0;
        if (dp[pos][t] != -1)
            return dp[pos][t];
        long long num = 0;
        for (int i = pos; i < s.size(); i++) {
            num = num * 10 + (s[i] - '0');
            if (num > t)
                break;
            if (canPartition(s, i + 1, t - num, dp)) {
                dp[pos][t] = 1;
                return true;
            }
        }
        dp[pos][t] = 0;
        return false;
    }

    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int sq = i * i;
            string s = to_string(sq);
            vector<vector<int>> dp(s.size(), vector<int>(i + 1, -1));
            if (canPartition(s, 0, i, dp))
                ans += sq;
        }
        return ans;
    }
};
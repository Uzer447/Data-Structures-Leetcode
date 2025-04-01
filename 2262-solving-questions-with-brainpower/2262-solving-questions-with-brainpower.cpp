class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            int next = i + questions[i][1] + 1;
            long long solve = questions[i][0] + (next < n ? dp[next] : 0);
            dp[i] = max(solve, dp[i + 1]);
        }
        return dp[0];
    }
};
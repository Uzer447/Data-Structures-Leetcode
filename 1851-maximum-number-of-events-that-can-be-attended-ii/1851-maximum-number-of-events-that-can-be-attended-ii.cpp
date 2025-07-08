class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());

        int n = events.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        vector<int> next(n, n);
        for (int i = 0; i < n; ++i) {
            int l = i + 1, r = n;
            while (l < r) {
                int m = l + (r - l) / 2;
                if (events[m][0] > events[i][1]) r = m;
                else l = m + 1;
            }
            next[i] = l;
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int t = 1; t <= k; ++t) {
                int take = events[i][2] + dp[next[i]][t - 1];
                int skip = dp[i + 1][t];
                dp[i][t] = max(take, skip);
            }
        }
        return dp[0][k];
    }
};

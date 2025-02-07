class Solution {
public:
    int dp[105][105];
    vector<int> pos[26];
    int n;
    int dfs(string &ring, string &key, int i, int j) {
        if (i == key.size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int res = INT_MAX;
        for (int k : pos[key[i]-'a']) {
            int diff = abs(j - k);
            int step = min(diff, n - diff) + 1;
            res = min(res, step + dfs(ring, key, i + 1, k));
        }
        dp[i][j] = res;
        return res;
    }
    int findRotateSteps(string ring, string key) {
        n = ring.size();
        for (int i = 0; i < 26; ++i) pos[i].clear();
        for (int i = 0; i < n; ++i) pos[ring[i]-'a'].push_back(i);
        memset(dp, -1, sizeof(dp));
        return dfs(ring, key, 0, 0);
    }
};
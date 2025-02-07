class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if (stones[1] != 1) return false;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i) mp[stones[i]] = i;
        vector<unordered_set<int>> dp(n);
        dp[0].insert(0);
        for (int i = 0; i < n; ++i) {
            for (int k : dp[i]) {
                for (int s = k - 1; s <= k + 1; ++s) {
                    if (s > 0) {
                        int next = stones[i] + s;
                        if (mp.count(next)) {
                            dp[mp[next]].insert(s);
                        }
                    }
                }
            }
        }
        return !dp[n - 1].empty();
    }
};
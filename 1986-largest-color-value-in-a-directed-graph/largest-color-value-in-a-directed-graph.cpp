class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        vector<int> indeg(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            ++indeg[e[1]];
        }
        vector<array<int,26>> dp(n);
        for (int i = 0; i < n; ++i) {
            dp[i].fill(0);
            dp[i][colors[i]-'a'] = 1;
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) if (!indeg[i]) q.push(i);
        int seen = 0, res = 0;
        while (!q.empty()) {
            int v = q.front(); q.pop();
            ++seen;
            for (int x : dp[v]) res = max(res, x);
            for (int u : adj[v]) {
                for (int c = 0; c < 26; ++c) {
                    int val = dp[v][c] + (c == colors[u]-'a');
                    if (val > dp[u][c]) dp[u][c] = val;
                }
                if (--indeg[u] == 0) q.push(u);
            }
        }
        return seen == n ? res : -1;
    }
};
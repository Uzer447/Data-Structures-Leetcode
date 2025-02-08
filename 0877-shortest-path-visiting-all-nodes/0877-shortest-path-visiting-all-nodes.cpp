class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<array<int, 3>> q;
        vector<vector<bool>> vis(n, vector<bool>(1 << n));
        for (int i = 0; i < n; ++i) {
            q.push({i, 1 << i, 0});
            vis[i][1 << i] = true;
        }
        int full = (1 << n) - 1;
        while (!q.empty()) {
            auto curr = q.front(); q.pop();
            int node = curr[0], mask = curr[1], dist = curr[2];
            if (mask == full) return dist;
            for (int nei : graph[node]) {
                int next_mask = mask | (1 << nei);
                if (!vis[nei][next_mask]) {
                    vis[nei][next_mask] = true;
                    q.push({nei, next_mask, dist + 1});
                }
            }
        }
        return 0;
    }
};
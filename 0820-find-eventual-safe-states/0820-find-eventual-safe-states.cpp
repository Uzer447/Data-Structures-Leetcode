class Solution {
    vector<int> color;
    vector<vector<int>> g;
    bool dfs(int u) {
        if (color[u])
            return color[u] == 2;
        color[u] = 1;
        for (int v : g[u])
            if (!dfs(v))
                return false;
        color[u] = 2;
        return true;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        g = graph;
        int n = g.size();
        color.resize(n);
        vector<int> ans;
        for (int i = 0; i < n; ++i)
            if (dfs(i))
                ans.push_back(i);
        return ans;
    }
};
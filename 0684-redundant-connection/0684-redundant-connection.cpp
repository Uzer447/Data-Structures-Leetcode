class Solution {
public:
    vector<int> parent;
    int find(int u) {
        return parent[u] == u ? u : parent[u] = find(parent[u]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        for (int i = 1; i <= n; ++i)
            parent[i] = i;
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            int pu = find(u), pv = find(v);
            if (pu == pv)
                return e;
            parent[pu] = pv;
        }
        return {};
    }
};
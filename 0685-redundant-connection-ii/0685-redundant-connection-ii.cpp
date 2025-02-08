class UnionFind {
public:
    vector<int> parent;
    UnionFind(int n) {
        parent.resize(n + 1);
        for (int i = 0; i <= n; ++i) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;
        parent[py] = px;
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1, 0), candidate1, candidate2;
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if (parent[v] == 0) {
                parent[v] = u;
            } else {
                candidate1 = {parent[v], v};
                candidate2 = {u, v};
                edge[1] = 0;
            }
        }
        UnionFind uf(n);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if (v == 0) continue;
            if (!uf.unite(u, v)) {
                if (candidate1.empty()) return edge;
                else return candidate1;
            }
        }
        return candidate2;
    }
};
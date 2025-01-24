class Solution {
public:
    vector<int> lowlink;
    vector<int> tin;
    vector<vector<int>> res;
    vector<bool> vis;
    int timer = 0;
    // return lowlink of children
    int dfs(int p, int i, unordered_map<int, vector<int>>& g) {
        if (vis[i]) return lowlink[i];

        timer++;
        vis[i] = 1; // first time visiting this node
        lowlink[i] = tin[i] = timer;

        for (auto nb: g[i]) {
            if (nb == p) continue;
            lowlink[i] = std::min(lowlink[i], dfs(i, nb, g));
        }

        if (p != -1 && lowlink[i] == tin[i]) res.push_back({p, i});

        return lowlink[i];
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        lowlink = vector<int>(n, INT_MAX);
        tin = vector<int>(n, INT_MAX);
        vis = vector<bool>(n, 0);

        unordered_map<int, vector<int>> g;
        for (auto& c: connections) {
            g[c[0]].push_back(c[1]);
            g[c[1]].push_back(c[0]);
        }

        dfs(-1, 0, g);

        return res;
    }
};
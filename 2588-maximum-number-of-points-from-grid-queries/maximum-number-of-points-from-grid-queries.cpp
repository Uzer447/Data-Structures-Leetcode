#include <bits/stdc++.h>
using namespace std;
struct DSU {
    vector<int> parent, sz;
    DSU(int n): parent(n), sz(n,1) { for (int i = 0; i < n; i++) parent[i] = i; }
    int find(int a) { return parent[a] == a ? a : parent[a] = find(parent[a]); }
    void join(int a, int b) { a = find(a), b = find(b); if (a == b) return; if (sz[a] < sz[b]) swap(a, b); parent[b] = a; sz[a] += sz[b]; }
};
class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size(), total = m * n;
        vector<tuple<int,int,int>> cells;
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++) 
                cells.push_back({grid[i][j], i, j});
        sort(cells.begin(), cells.end(), [](auto &a, auto &b){ return get<0>(a) < get<0>(b); });
        int k = queries.size();
        vector<pair<int,int>> qs;
        for (int i = 0; i < k; i++) qs.push_back({queries[i], i});
        sort(qs.begin(), qs.end());
        vector<int> ans(k, 0);
        vector<bool> active(total, false);
        DSU dsu(total);
        int pointer = 0;
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        for (auto &q : qs) {
            int query = q.first, idx = q.second;
            while (pointer < cells.size() && get<0>(cells[pointer]) < query) {
                int val, r, c; tie(val, r, c) = cells[pointer];
                int pos = r * n + c;
                active[pos] = true;
                for (auto &d : dirs) {
                    int nr = r + d[0], nc = c + d[1];
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                        int pos2 = nr * n + nc;
                        if (active[pos2]) dsu.join(pos, pos2);
                    }
                }
                pointer++;
            }
            if (active[0]) ans[idx] = dsu.sz[dsu.find(0)];
            else ans[idx] = 0;
        }
        return ans;
    }
};
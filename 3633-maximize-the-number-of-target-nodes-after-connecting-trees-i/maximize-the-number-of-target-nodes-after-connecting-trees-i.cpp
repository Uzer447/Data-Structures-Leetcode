class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1, m = edges2.size() + 1;

        vector<vector<int>> g1(n), g2(m);
        for (auto& e : edges1) {
            g1[e[0]].push_back(e[1]);
            g1[e[1]].push_back(e[0]);
        }
        for (auto& e : edges2) {
            g2[e[0]].push_back(e[1]);
            g2[e[1]].push_back(e[0]);
        }

        vector<int> inside(n);
        vector<array<uint64_t, 16>> exist(n); 
        queue<int> q;
        vector<int> dist(max(n, m));

        for (int s = 0; s < n; ++s) {
            fill(dist.begin(), dist.begin() + n, -1);
            dist[s] = 0;
            q.push(s);
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                if (dist[u] <= k)
                    ++inside[s];
                if (dist[u] <= k - 1)
                    exist[s][dist[u] >> 6] |= 1ULL << (dist[u] & 63);
                for (int v : g1[u])
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
            }
        }

        vector<int> best(k + 1);
        vector<vector<int>> cnt(m, vector<int>(k + 1));
        for (int s = 0; s < m; ++s) {
            fill(dist.begin(), dist.begin() + m, -1);
            dist[s] = 0;
            q.push(s);
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                if (dist[u] <= k)
                    ++cnt[s][dist[u]];
                for (int v : g2[u])
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
            }
            for (int r = 1; r <= k; ++r)
                cnt[s][r] += cnt[s][r - 1];
            for (int r = 0; r <= k; ++r)
                best[r] = max(best[r], cnt[s][r]);
        }

        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            int add = 0;
            for (int r = 0; r <= k - 1; ++r) {
                int d = k - r - 1;
                if (d < 0)
                    continue;
                if ((exist[i][d >> 6] >> (d & 63)) & 1ULL)
                    add = max(add, best[r]);
            }
            ans[i] = inside[i] + add;
        }
        return ans;
    }
};
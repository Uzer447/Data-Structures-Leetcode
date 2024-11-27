class Solution {
public:
    int dijkstra(int V, vector<vector<int>> &adj, int S) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        vector<int> distTo(V, INT_MAX);
        distTo[S] = 0;
        pq.push({0, S});
        while (!pq.empty()) {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            for (auto it : adj[node]) {
                int v = it;
                int w = 1;
                if (dis + w < distTo[v]) {
                    distTo[v] = dis + w;
                    pq.push({dis + w, v});
                }
            }
        }
        return distTo[V-1];
    }
    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            if (i + 1 < n)
                adj[i].push_back(i + 1);
        }
        vector<int> ans;
        for (auto& it : queries) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            ans.push_back(dijkstra(n,adj,0));
        }
        return ans;
    }
};
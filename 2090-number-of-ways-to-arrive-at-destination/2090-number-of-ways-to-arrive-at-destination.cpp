class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<vector<pair<int,int>>> graph(n);
        for(auto &r : roads){
            int u = r[0], v = r[1], w = r[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
        vector<long long> dist(n, 1e18);
        vector<int> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        pq.push({0, 0});
        while(!pq.empty()){
            auto [d, u] = pq.top();
            pq.pop();
            if(d > dist[u]) continue;
            for(auto &edge : graph[u]){
                int v = edge.first, w = edge.second;
                long long nd = d + w;
                if(nd < dist[v]){
                    dist[v] = nd;
                    ways[v] = ways[u];
                    pq.push({nd, v});
                } else if(nd == dist[v]){
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
        return ways[n-1];
    }
};
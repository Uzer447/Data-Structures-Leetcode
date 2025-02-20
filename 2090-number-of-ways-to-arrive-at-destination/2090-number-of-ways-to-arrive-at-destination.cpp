class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> adj[n];
        int mod=1e9+7;
        for (auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                      greater<pair<long long, int>>>
            pq;
        pq.push({0,0});
        vector<long long> dist(n,1e15);
        vector<long long> ways(n,0);
        ways[0]=1;
        dist[0]=0;
        while(!pq.empty())
        {
            long long dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if (node == n - 1)
            {
                break;
            }
            for(auto it:adj[node])
            {
                int adjNode=it.first;
                long long edW=it.second;
                if(dis+edW<dist[adjNode])
                {
                    dist[adjNode]=dis+edW;
                    pq.push({dis+edW,adjNode});
                    ways[adjNode]=ways[node];
                }
                else if(dis+edW==dist[adjNode])
                {
                    ways[adjNode]=(ways[adjNode]+ways[node])%mod;
                }
            }
        }
        return (int)(ways[n-1]%mod);
    }
};
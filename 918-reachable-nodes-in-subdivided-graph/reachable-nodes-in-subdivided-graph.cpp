#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int,int>>> g(n);
        for(auto &e : edges){
            int u = e[0], v = e[1], cnt = e[2];
            g[u].push_back({v, cnt});
            g[v].push_back({u, cnt});
        }
        const long long INF = 1LL << 60;
        vector<long long> dist(n, INF);
        dist[0] = 0;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        pq.push({0, 0});
        while(!pq.empty()){
            auto [d, u] = pq.top();
            pq.pop();
            if(d != dist[u]) continue;
            for(auto &p : g[u]){
                int v = p.first, cnt = p.second;
                long long nd = d + cnt + 1;
                if(nd < dist[v]){
                    dist[v] = nd;
                    pq.push({nd, v});
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++){
            if(dist[i] <= maxMoves)
                ans++;
        }
        for(auto &e : edges){
            int u = e[0], v = e[1], cnt = e[2];
            long long a = (dist[u] <= maxMoves ? maxMoves - dist[u] : 0);
            long long b = (dist[v] <= maxMoves ? maxMoves - dist[v] : 0);
            ans += min((long long)cnt, a + b);
        }
        return ans;
    }
};
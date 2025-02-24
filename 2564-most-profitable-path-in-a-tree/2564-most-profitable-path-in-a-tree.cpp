#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    vector<vector<int>> g;
    vector<int> bobTime;
    vector<int> a;
    int n;
    long long best;
 
    void dfs(int u, int t, long long sum, int p) {
        if(t < bobTime[u]) sum += a[u];
        else if(t == bobTime[u]) sum += a[u] / 2;
        bool leaf = true;
        for (int v : g[u]) {
            if(v == p) continue;
            leaf = false;
            dfs(v, t + 1, sum, u);
        }
        if(leaf) best = max(best, sum);
    }
 
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        a = amount;
        n = a.size();
        g.assign(n, vector<int>());
        for(auto &e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<int> par(n, -1);
        queue<int> qu;
        par[0] = -1;
        qu.push(0);
        while(!qu.empty()){
            int u = qu.front();
            qu.pop();
            for(int v : g[u]){
                if(v == par[u]) continue;
                par[v] = u;
                qu.push(v);
            }
        }
        bobTime.assign(n, INT_MAX);
        int t = 0, cur = bob;
        while(cur != -1){
            bobTime[cur] = t++;
            cur = par[cur];
        }
        best = -LLONG_MAX;
        dfs(0, 0, 0LL, -1);
        return best;
    }
};
class Solution {
public:
    bool dfs(int node,int col,vector<vector<int>> &adj,vector<int> &color)
    {
        color[node]=col;
        for(auto it:adj[node])
        {
            if(color[it]==-1)
            {
                if(dfs(it,1-col,adj,color)==false)
                return false;
            }
            else if(color[it]==color[node])
            {
                return false;
            }
        }
        return true;
    }
    bool check(int src,vector<vector<int>>& adj, vector<int>& color) {
        queue<int> q;
        color[src] = 0;
        q.push(src);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto it : adj[node]) {
                if (color[it] == -1) {
                    q.push(it);
                    color[it] = 1 - color[node];
                } else {
                    if (color[it] == color[node])
                        return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);
        for (int i = 0; i < graph.size(); i++) {
            if (color[i] == -1) {
            if(dfs(i,0,graph,color)==false)
            return false;
            }
        }
        return true;
    }
};
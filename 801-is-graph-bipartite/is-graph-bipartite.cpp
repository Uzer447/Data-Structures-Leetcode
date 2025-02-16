class Solution {
public:
    bool check(int src,vector<vector<int>> &graph,vector<char> &vis)
    {
        queue<pair<int,char>> q;
        q.push({src,'A'});
        vis[src]='A';
        while(!q.empty())
        {
            int node=q.front().first;
            int color=q.front().second;
            q.pop();
            for(auto it:graph[node])
            {
                if(vis[it]=='#')
                {
                    q.push({it,(color=='A'?'B':'A')});
                    vis[it]=(color=='A'?'B':'A');
                }
                else 
                {
                    if(vis[it]==color)
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<char> vis(n,'#');
        for(int i=0;i<n;i++)
        {
            if(vis[i]=='#')
            {
                if(check(i,graph,vis)==false)
                return false;
            }
        }
        return true;
    }
};
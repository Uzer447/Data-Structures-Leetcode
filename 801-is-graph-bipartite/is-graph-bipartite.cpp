class Solution {
public:
    bool bfs(int node,vector<vector<int>> &graph,vector<int> &col)
    {
        queue<pair<int,int>> q;
        q.push({node,1});
        col[node]=1;
        while(!q.empty())
        {
            int node=q.front().first;
            int color=q.front().second;
            q.pop();
            for(auto it:graph[node])
            {
                if(col[it]==-1)
                {
                    col[it]=(color==2)?1:2;
                    q.push({it,col[it]});
                }
                else if(col[it]==color)
                {
                    return false;
                }
                else
                {
                    continue;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> col(n,-1);
        for(int i=0;i<n;i++)
        {
            if(col[i]==-1)
            {
                if(bfs(i,graph,col)==false)
                    return false;
            }
        }
        return true;
    }
};
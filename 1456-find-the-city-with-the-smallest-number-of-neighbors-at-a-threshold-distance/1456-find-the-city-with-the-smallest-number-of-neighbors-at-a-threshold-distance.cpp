class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adj(n,vector<int>(n,INT_MAX));
        for(auto it:edges)
        {
            adj[it[0]][it[1]]=it[2];
            adj[it[1]][it[0]]=it[2];
        }
        for (int i = 0; i < n; i++) adj[i][i] = 0;
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if (adj[i][k] == INT_MAX || adj[k][j] == INT_MAX)
						continue;
                    adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
                }
            }
        }
        int cntmax=n;
        int city=-1;
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                if(adj[i][j]<=distanceThreshold)
                cnt++;
            }
            if(cnt<=cntmax)
            {
                cntmax=cnt;
                city=i;
            }
        }
        return  city;
    }
};
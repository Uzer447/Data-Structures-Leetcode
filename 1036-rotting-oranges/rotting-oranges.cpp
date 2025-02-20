class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis=grid;
        int cntfresh=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                }
                if(grid[i][j]==1)
                cntfresh++;
            }
        }
        vector<int> dx={0,-1,0,1};
        vector<int> dy={-1,0,1,0};
        int mxtime=0;
        while(!q.empty())
        {
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                int row=q.front().first.first;
                int col=q.front().first.second;
                int time=q.front().second;
                mxtime=max(mxtime,time);
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int nrow=row+dx[i];
                    int ncol=col+dy[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1)
                    {
                        grid[nrow][ncol]=2;
                        cntfresh--;
                        q.push({{nrow,ncol},time+1});
                    }
                }
            }
        }
        if(cntfresh==0)
        return mxtime;
        return -1;
    }
};
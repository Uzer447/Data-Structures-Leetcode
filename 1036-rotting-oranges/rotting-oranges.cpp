class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,pair<int,int>>> q;
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({0,{i,j}});
                } else if (grid[i][j]==1){
                    cnt++;
                }
            }
        }
        int time=0;
        int maxtime=0;
        while(!q.empty()){
            int row=q.front().second.first;
            int col=q.front().second.second;
            int time=q.front().first;
            maxtime=max(maxtime,time);
            q.pop();
            int dr[]={-1,0,+1,0};
            int dc[]={0,-1,0,+1};
            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1){
                    grid[nrow][ncol]=2;
                    cnt--;
                    q.push({time+1,{nrow,ncol}});
                }
            }
        }
        if(cnt>0) return -1;
        return maxtime;
    }
};
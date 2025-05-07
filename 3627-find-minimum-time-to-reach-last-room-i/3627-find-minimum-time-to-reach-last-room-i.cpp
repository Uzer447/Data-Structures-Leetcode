class Solution {
public:
    int minTimeToReach(vector<vector<int>>& g) {
        int n=g.size(),m=g[0].size();
        const long long INF=4e18;
        vector<vector<long long>> d(n,vector<long long>(m,INF));
        using T=tuple<long long,int,int>;
        priority_queue<T,vector<T>,greater<T>> pq;
        d[0][0]=0;
        pq.emplace(0,0,0);
        int dr[4]={1,-1,0,0},dc[4]={0,0,1,-1};
        while(!pq.empty()){
            auto[t,r,c]=pq.top();pq.pop();
            if(t!=d[r][c])continue;
            if(r==n-1&&c==m-1)return t;
            for(int k=0;k<4;k++){
                int nr=r+dr[k],nc=c+dc[k];
                if(nr<0||nr>=n||nc<0||nc>=m)continue;
                long long nt=max<long long>(t,g[nr][nc])+1;
                if(nt<d[nr][nc]){
                    d[nr][nc]=nt;
                    pq.emplace(nt,nr,nc);
                }
            }
        }
        return -1;
    }
};
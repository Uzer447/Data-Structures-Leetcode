class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        const long long INF = 4e18;
        auto idx = [&](int i,int j,int p){ return (((i*m)+j)<<1)|p; };
        int tot = n*m*2;
        vector<long long> dist(tot,INF);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        dist[idx(0,0,0)]=0;
        pq.push({0,idx(0,0,0)});
        int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
        while(!pq.empty()){
            auto [t,u]=pq.top();pq.pop();
            if(t!=dist[u]) continue;
            int p=u&1;
            int k=u>>1, i=k/m, j=k%m;
            if(i==n-1 && j==m-1) return (int)t;
            int step=p?2:1, np=p^1;
            for(int d=0;d<4;++d){
                int x=i+dx[d], y=j+dy[d];
                if(x<0||x>=n||y<0||y>=m) continue;
                long long start=max<long long>(t,moveTime[x][y]);
                long long arrive=start+step;
                int v=idx(x,y,np);
                if(arrive<dist[v]){
                    dist[v]=arrive;
                    pq.push({arrive,v});
                }
            }
        }
        return -1;
    }
};
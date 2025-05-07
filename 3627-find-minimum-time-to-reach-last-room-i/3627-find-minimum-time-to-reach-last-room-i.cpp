class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        const long long INF = 4e18;
        vector<vector<long long>> dist(n, vector<long long>(m, INF));
        using State = tuple<long long,int,int>;
        priority_queue<State, vector<State>, greater<State>> pq;
        dist[0][0] = 0;
        pq.emplace(0,0,0);
        int dr[4]={1,-1,0,0}, dc[4]={0,0,1,-1};
        while(!pq.empty()){
            auto [t,r,c]=pq.top(); pq.pop();
            if(t!=dist[r][c]) continue;
            if(r==n-1 && c==m-1) return t;
            for(int k=0;k<4;k++){
                int nr=r+dr[k], nc=c+dc[k];
                if(nr<0||nr>=n||nc<0||nc>=m) continue;
                long long depart=max<long long>(t,moveTime[nr][nc]);
                long long arr=depart+1;
                if(arr<dist[nr][nc]){
                    dist[nr][nc]=arr;
                    pq.emplace(arr,nr,nc);
                }
            }
        }
        return -1;
    }
};
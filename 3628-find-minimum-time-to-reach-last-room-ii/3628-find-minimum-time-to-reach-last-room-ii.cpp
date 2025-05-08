class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        const long long INF = 4e18;
        vector<vector<array<long long,2>>> dist(n, vector<array<long long,2>>(m, {INF, INF}));
        using State = tuple<long long,int,int,int>;
        priority_queue<State, vector<State>, greater<State>> pq;
        dist[0][0][0] = 0;
        pq.push({0,0,0,0});
        int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
        while(!pq.empty()){
            auto [t,i,j,p] = pq.top(); pq.pop();
            if(t!=dist[i][j][p]) continue;
            if(i==n-1 && j==m-1) return (int)t;
            int step = p ? 2 : 1, np = p ^ 1;
            for(int d=0; d<4; ++d){
                int x = i + dx[d], y = j + dy[d];
                if(x<0 || x>=n || y<0 || y>=m) continue;
                long long start = max<long long>(t, moveTime[x][y]);
                long long arrive = start + step;
                if(arrive < dist[x][y][np]){
                    dist[x][y][np] = arrive;
                    pq.push({arrive, x, y, np});
                }
            }
        }
        return -1;
    }
};
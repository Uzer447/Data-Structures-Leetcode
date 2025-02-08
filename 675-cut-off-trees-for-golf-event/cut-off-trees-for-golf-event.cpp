#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class Solution {
public:
    int cutOffTree(vector<vector<int>>& f) {
        int m = f.size(), n = f[0].size();
        vector<vector<int>> t;
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
                if(f[i][j]>1)
                    t.push_back({f[i][j], i, j});
        sort(t.begin(), t.end());
        int ans=0, x=0, y=0;
        for(auto& a : t) {
            int d = bfs(f, x, y, a[1], a[2]);
            if(d==-1) return -1;
            ans += d;
            x = a[1]; y = a[2];
            f[x][y]=1;
        }
        return ans;
    }

    int bfs(vector<vector<int>>& f, int x0, int y0, int x1, int y1) {
        if(x0==x1 && y0==y1) return 0;
        int m = f.size(), n = f[0].size();
        queue<pair<int,int>> q;
        q.push({x0,y0});
        vector<vector<int>> v(m, vector<int>(n,0));
        v[x0][y0]=1;
        int d=0;
        int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto [x,y] = q.front(); q.pop();
                if(x==x1 && y==y1) return d;
                for(auto& dir : dirs) {
                    int nx = x+dir[0], ny=y+dir[1];
                    if(nx>=0 && nx<m && ny>=0 && ny<n && f[nx][ny]>0 && !v[nx][ny]) {
                        v[nx][ny]=1;
                        q.push({nx,ny});
                    }
                }
            }
            ++d;
        }
        return -1;
    }
};
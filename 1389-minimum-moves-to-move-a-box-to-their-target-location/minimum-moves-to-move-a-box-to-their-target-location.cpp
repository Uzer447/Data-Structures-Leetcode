#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minPushBox(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), bx, by, sx, sy, tx, ty;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]=='B') { bx = i; by = j; }
                else if(grid[i][j]=='S') { sx = i; sy = j; }
                else if(grid[i][j]=='T') { tx = i; ty = j; }
            }
        }
        vector<vector<vector<vector<bool>>>> vis(m, vector<vector<vector<bool>>>(n, vector<vector<bool>>(m, vector<bool>(n, false))));
        auto canReach = [&](int xs, int ys, int xt, int yt, int cbx, int cby) -> bool {
            vector<vector<bool>> seen(m, vector<bool>(n, false));
            queue<pair<int,int>> q;
            q.push({xs,ys});
            seen[xs][ys] = true;
            int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
            while(!q.empty()){
                auto [x,y] = q.front();
                q.pop();
                if(x==xt && y==yt) return true;
                for(auto &d: dirs){
                    int nx = x+d[0], ny = y+d[1];
                    if(nx>=0 && nx<m && ny>=0 && ny<n && !seen[nx][ny] && grid[nx][ny]!='#' && !(nx==cbx && ny==cby)){
                        seen[nx][ny] = true;
                        q.push({nx,ny});
                    }
                }
            }
            return false;
        };
        struct State { int bx, by, sx, sy, pushes; };
        queue<State> qu;
        qu.push({bx,by,sx,sy,0});
        vis[bx][by][sx][sy] = true;
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!qu.empty()){
            auto cur = qu.front();
            qu.pop();
            if(cur.bx==tx && cur.by==ty) return cur.pushes;
            for(auto &d: dirs){
                int nbx = cur.bx + d[0], nby = cur.by + d[1];
                int reqx = cur.bx - d[0], reqy = cur.by - d[1];
                if(nbx < 0 || nbx >= m || nby < 0 || nby >= n || reqx < 0 || reqx >= m || reqy < 0 || reqy >= n) continue;
                if(grid[nbx][nby]=='#') continue;
                if(grid[reqx][reqy]=='#') continue;
                if(!canReach(cur.sx, cur.sy, reqx, reqy, cur.bx, cur.by)) continue;
                if(!vis[nbx][nby][cur.bx][cur.by]){
                    vis[nbx][nby][cur.bx][cur.by] = true;
                    qu.push({nbx, nby, cur.bx, cur.by, cur.pushes+1});
                }
            }
        }
        return -1;
    }
};
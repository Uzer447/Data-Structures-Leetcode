#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<bool>>> vis(n, vector<vector<bool>>(n, vector<bool>(2, false)));
        queue<tuple<int,int,int,int>> q;
        q.push({0,0,0,0});
        vis[0][0][0] = true;
        while(!q.empty()){
            auto [r, c, o, moves] = q.front();
            q.pop();
            if(r == n-1 && c == n-2 && o == 0) return moves;
            if(o == 0){
                if(c + 2 < n && grid[r][c+2] == 0 && !vis[r][c+1][0]){
                    vis[r][c+1][0] = true;
                    q.push({r, c+1, 0, moves+1});
                }
                if(r + 1 < n && grid[r+1][c] == 0 && grid[r+1][c+1] == 0 && !vis[r+1][c][0]){
                    vis[r+1][c][0] = true;
                    q.push({r+1, c, 0, moves+1});
                }
                if(r + 1 < n && grid[r+1][c] == 0 && grid[r+1][c+1] == 0 && !vis[r][c][1]){
                    vis[r][c][1] = true;
                    q.push({r, c, 1, moves+1});
                }
            } else {
                if(r + 2 < n && grid[r+2][c] == 0 && !vis[r+1][c][1]){
                    vis[r+1][c][1] = true;
                    q.push({r+1, c, 1, moves+1});
                }
                if(c + 1 < n && grid[r][c+1] == 0 && grid[r+1][c+1] == 0 && !vis[r][c+1][1]){
                    vis[r][c+1][1] = true;
                    q.push({r, c+1, 1, moves+1});
                }
                if(c + 1 < n && grid[r][c+1] == 0 && grid[r+1][c+1] == 0 && !vis[r][c][0]){
                    vis[r][c][0] = true;
                    q.push({r, c, 0, moves+1});
                }
            }
        }
        return -1;
    }
};
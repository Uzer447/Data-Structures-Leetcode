#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        int n = blocked.size();
        if(n == 0)return true;
        long long bound = 1000000, limit = (long long)n*(n - 1)/2;
        unordered_set<long long> blockedSet;
        for(auto &b : blocked) blockedSet.insert(((long long)b[0] << 20) | b[1]);
        auto bfs = [&](vector<int> start, vector<int> finish) -> bool {
            unordered_set<long long> visited;
            queue<pair<int,int>> q;
            auto encode = [&](int x, int y) -> long long { return ((long long)x << 20) | y; };
            q.push({start[0], start[1]});
            visited.insert(encode(start[0], start[1]));
            int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
            while(!q.empty()){
                auto [x, y] = q.front();
                q.pop();
                if(x == finish[0] && y == finish[1]) return true;
                if(visited.size() > limit) return true;
                for(auto &d : dirs){
                    int nx = x + d[0], ny = y + d[1];
                    if(nx < 0 || ny < 0 || nx >= bound || ny >= bound) continue;
                    long long code = encode(nx, ny);
                    if(blockedSet.count(code)) continue;
                    if(visited.count(code)) continue;
                    visited.insert(code);
                    q.push({nx, ny});
                }
            }
            return false;
        };
        return bfs(source, target) && bfs(target, source);
    }
};
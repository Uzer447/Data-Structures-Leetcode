#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<long long,int> active;
        unordered_map<int,int> row, col, diag, anti;
        auto encode = [&](int r, int c) -> long long {
            return (long long)r * n + c;
        };
        for(auto &lamp : lamps){
            int r = lamp[0], c = lamp[1];
            long long key = encode(r, c);
            if(active.count(key)) continue;
            active[key] = 1;
            row[r]++;
            col[c]++;
            diag[r - c]++;
            anti[r + c]++;
        }
        vector<int> ans;
        for(auto &q : queries) {
            int r = q[0], c = q[1];
            if(row[r] > 0 || col[c] > 0 || diag[r-c] > 0 || anti[r+c] > 0)
                ans.push_back(1);
            else
                ans.push_back(0);
            for (int i = r - 1; i <= r + 1; i++){
                for (int j = c - 1; j <= c + 1; j++){
                    if(i < 0 || i >= n || j < 0 || j >= n) continue;
                    long long key = encode(i, j);
                    if(active.count(key)){
                        active.erase(key);
                        if(--row[i] == 0) row.erase(i);
                        if(--col[j] == 0) col.erase(j);
                        if(--diag[i - j] == 0) diag.erase(i - j);
                        if(--anti[i + j] == 0) anti.erase(i + j);
                    }
                }
            }
        }
        return ans;
    }
};
#include <bits/stdc++.h>
using namespace std;
 
struct DSU {
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n); rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    void unionn(int a, int b) {
        a = find(a), b = find(b);
        if(a == b) return;
        if(rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        if(rank[a] == rank[b]) rank[a]++;
    }
};
 
class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DSU dsu(n);
        for(auto &e : edges) {
            dsu.unionn(e[0], e[1]);
        }
        int ALL_ONES = (1 << 18) - 1;
        unordered_map<int,int> comp_mask;
        for(int i = 0; i < n; i++){
            int root = dsu.find(i);
            if(comp_mask.find(root) == comp_mask.end()) comp_mask[root] = ALL_ONES;
        }
        for(auto &e : edges){
            int root = dsu.find(e[0]);
            comp_mask[root] &= e[2];
        }
        vector<int> res;
        for(auto &q : query){
            if(dsu.find(q[0]) != dsu.find(q[1])) res.push_back(-1);
            else res.push_back(comp_mask[dsu.find(q[0])]);
        }
        return res;
    }
};
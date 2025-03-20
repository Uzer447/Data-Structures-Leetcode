#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();
        vector<int> parent(n), rank(n, 0);
        iota(parent.begin(), parent.end(), 0);
        function<int(int)> findp = [&](int x) -> int {
            return parent[x] = (parent[x] == x ? x : findp(parent[x]));
        };
        auto unionn = [&](int x, int y) {
            int rx = findp(x), ry = findp(y);
            if(rx == ry) return;
            if(rank[rx] < rank[ry]) parent[rx] = ry;
            else if(rank[rx] > rank[ry]) parent[ry] = rx;
            else { parent[ry] = rx; rank[rx]++; }
        };
        unordered_map<int, int> factorIndex;
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            for (int factor = 2; factor * factor <= num; factor++) {
                if(num % factor == 0) {
                    while(num % factor == 0) num /= factor;
                    if(factorIndex.count(factor)) unionn(i, factorIndex[factor]);
                    else factorIndex[factor] = i;
                }
            }
            if(num > 1) {
                if(factorIndex.count(num)) unionn(i, factorIndex[num]);
                else factorIndex[num] = i;
            }
        }
        unordered_map<int, int> count;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int root = findp(i);
            ans = max(ans, ++count[root]);
        }
        return ans;
    }
};
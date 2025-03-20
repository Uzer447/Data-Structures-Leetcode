#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
        unordered_map<int,int> dp;
        dp[-1] = 0;
        for (int x : arr1) {
            unordered_map<int,int> ndp;
            for (auto &p : dp) {
                int prev = p.first, ops = p.second;
                if (x > prev)
                    ndp[x] = ndp.count(x) ? min(ndp[x], ops) : ops;
                int idx = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();
                if (idx < arr2.size())
                    ndp[arr2[idx]] = ndp.count(arr2[idx]) ? min(ndp[arr2[idx]], ops + 1) : ops + 1;
            }
            if (ndp.empty()) return -1;
            dp = move(ndp);
        }
        int ans = INT_MAX;
        for (auto &p : dp)
            ans = min(ans, p.second);
        return ans;
    }
};
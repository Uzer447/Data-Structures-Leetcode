#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int x;
    unordered_map<string,int> memo;
    int dp(int i, int target) {
        string key = to_string(i) + "#" + to_string(target);
        if(memo.count(key)) return memo[key];
        int ans;
        if(target == 0) ans = 0;
        else if(target == 1) ans = (i > 0 ? i : 2);
        else if(i >= 39) ans = target + 1;
        else {
            int t = target / x, r = target % x;
            ans = min(r * (i > 0 ? i : 2) + dp(i+1, t),
                      (x - r) * (i > 0 ? i : 2) + dp(i+1, t+1));
        }
        memo[key] = ans;
        return ans;
    }
    int leastOpsExpressTarget(int x, int target) {
        memo.clear();
        this->x = x;
        return dp(0, target) - 1;
    }
};
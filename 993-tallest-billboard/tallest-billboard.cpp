#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstdlib>
using namespace std;
class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        unordered_map<int,int> dp;
        dp[0] = 0;
        for (int rod : rods) {
            auto cur = dp;
            for (auto& p : cur) {
                dp[p.first + rod] = max(dp[p.first + rod], p.second);
                dp[abs(p.first - rod)] = max(dp[abs(p.first - rod)], p.second + min(rod, p.first));
            }
        }
        return dp[0];
    }
};
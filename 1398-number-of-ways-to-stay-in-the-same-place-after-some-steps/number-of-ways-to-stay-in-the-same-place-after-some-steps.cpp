#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numWays(int steps, int arrLen) {
        int mod = 1000000007;
        int maxPos = min(arrLen - 1, steps);
        vector<int> dp(maxPos + 1, 0), ndp(maxPos + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < steps; i++) {
            fill(ndp.begin(), ndp.end(), 0);
            for (int j = 0; j <= maxPos; j++) {
                ndp[j] = (ndp[j] + dp[j]) % mod;
                if (j > 0)
                    ndp[j - 1] = (ndp[j - 1] + dp[j]) % mod;
                if (j < maxPos)
                    ndp[j + 1] = (ndp[j + 1] + dp[j]) % mod;
            }
            dp = ndp;
        }
        return dp[0];
    }
};
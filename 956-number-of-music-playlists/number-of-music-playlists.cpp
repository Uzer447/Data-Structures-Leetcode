#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        const long long MOD = 1000000007;
        vector<vector<long long>> dp(goal + 1, vector<long long>(n + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i < goal; i++)
            for (int j = 0; j <= n; j++) {
                if (dp[i][j] == 0) continue;
                if (n - j > 0) dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j] * (n - j)) % MOD;
                if (j > k) dp[i + 1][j] = (dp[i + 1][j] + dp[i][j] * (j - k)) % MOD;
            }
        return dp[goal][n];
    }
};
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        const int MOD = 1000000007;
        int m = group.size();
        vector<vector<int>> dp(n+1, vector<int>(minProfit+1, 0));
        dp[0][0] = 1;
        for (int i = 0; i < m; i++) {
            int req = group[i], earn = profit[i];
            for (int j = n; j >= req; j--) {
                for (int k = minProfit; k >= 0; k--) {
                    int newProfit = min(minProfit, k + earn);
                    dp[j][newProfit] = (dp[j][newProfit] + dp[j-req][k]) % MOD;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            ans = (ans + dp[i][minProfit]) % MOD;
        }
        return ans;
    }
};
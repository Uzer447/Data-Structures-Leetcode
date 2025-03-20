#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int palindromePartition(string s, int k) {
        int n = s.size();
        vector<vector<int>> cost(n, vector<int>(n, 0));
        for (int i = n - 1; i >= 0; i--)
            for (int j = i; j < n; j++)
                cost[i][j] = (i == j) ? 0 : (s[i] == s[j] ? (j - i < 2 ? 0 : cost[i + 1][j - 1]) : (j - i < 2 ? 1 : cost[i + 1][j - 1] + 1));
        const int INF = 1e9;
        vector<vector<int>> dp(n, vector<int>(k + 1, INF));
        for (int i = 0; i < n; i++)
            dp[i][1] = cost[0][i];
        for (int part = 2; part <= k; part++)
            for (int i = part - 1; i < n; i++)
                for (int j = part - 2; j < i; j++)
                    dp[i][part] = min(dp[i][part], dp[j][part - 1] + cost[j + 1][i]);
        return dp[n - 1][k];
    }
};
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size(), mod = 1000000007;
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        vector<int> last(128, 0);
        for (int i = 1; i <= n; i++) {
            dp[i] = (dp[i - 1] * 2) % mod;
            dp[i] = (dp[i] - (last[s[i - 1]] ? dp[last[s[i - 1]] - 1] : 0) + mod) % mod;
            last[s[i - 1]] = i;
        }
        return (dp[n] - 1 + mod) % mod;
    }
};
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numPermsDISequence(string s) {
        int n = s.size();
        const int mod = 1000000007;
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++){
            vector<int> pref(i,0);
            pref[0] = dp[i-1][0];
            for(int j = 1; j < i; j++){
                pref[j] = (pref[j-1] + dp[i-1][j]) % mod;
            }
            if(s[i-1]=='I'){
                for(int j = 0; j <= i; j++){
                    dp[i][j] = (j == 0 ? 0 : pref[j-1]);
                }
            } else {
                for(int j = 0; j <= i; j++){
                    int total = pref[i-1];
                    int left = (j > 0 ? pref[j-1] : 0);
                    dp[i][j] = (total - left + mod) % mod;
                }
            }
        }
        int ans = 0;
        for(int j = 0; j <= n; j++){
            ans = (ans + dp[n][j]) % mod;
        }
        return ans;
    }
};
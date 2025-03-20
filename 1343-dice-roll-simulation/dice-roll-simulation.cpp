#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        const long long MOD = 1000000007;
        vector<vector<long long>> dp(6), ndp(6);
        for (int i = 0; i < 6; i++){
            dp[i].resize(rollMax[i] + 1, 0);
            dp[i][1] = 1;
        }
        for (int roll = 1; roll < n; roll++){
            ndp.assign(6, vector<long long>());
            for (int i = 0; i < 6; i++){
                ndp[i].resize(rollMax[i] + 1, 0);
            }
            for (int face = 0; face < 6; face++){
                for (int cnt = 1; cnt <= rollMax[face]; cnt++){
                    if (dp[face][cnt] > 0){
                        long long ways = dp[face][cnt];
                        if (cnt < rollMax[face])
                            ndp[face][cnt + 1] = (ndp[face][cnt + 1] + ways) % MOD;
                        for (int nface = 0; nface < 6; nface++){
                            if (nface == face)
                                continue;
                            ndp[nface][1] = (ndp[nface][1] + ways) % MOD;
                        }
                    }
                }
            }
            dp = ndp;
        }
        long long ans = 0;
        for (int face = 0; face < 6; face++){
            for (int cnt = 1; cnt <= rollMax[face]; cnt++){
                ans = (ans + dp[face][cnt]) % MOD;
            }
        }
        return ans;
    }
};
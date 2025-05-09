#include <bits/stdc++.h>
using namespace std;

class Solution {
    static const int MOD = 1000000007;
    long long fpow(long long a,long long e){
        long long r=1;
        while(e){
            if(e&1) r=r*a%MOD;
            a=a*a%MOD;
            e>>=1;
        }
        return r;
    }
public:
    int countBalancedPermutations(string num){
        int n = num.size();
        vector<int> cnt(10);
        int sum = 0;
        for(char c:num){ cnt[c-'0']++; sum += c-'0'; }
        if(sum&1) return 0;
        int need = sum>>1;
        int ne = (n+1)>>1, no = n>>1;

        long long fact[81], invf[81];
        bool built = false;
        if(!built){
            built = true;
            fact[0]=1;
            for(int i=1;i<=80;i++) fact[i]=fact[i-1]*i%MOD;
            invf[80]=fpow(fact[80],MOD-2);
            for(int i=80;i>=1;i--) invf[i-1]=invf[i]*i%MOD;
        }

        vector<vector<long long>> dp(ne+1, vector<long long>(need+1));
        dp[0][0]=1;
        for(int d=0;d<=9;d++){
            int c = cnt[d];
            if(!c) continue;
            vector<vector<long long>> ndp(ne+1, vector<long long>(need+1));
            for(int e=0;e<=ne;e++) for(int s=0;s<=need;s++) if(dp[e][s]){
                long long cur = dp[e][s];
                for(int k=0;k<=c && e+k<=ne;k++){
                    int ns = s + k*d;
                    if(ns>need) break;
                    long long add = cur * invf[k] % MOD * invf[c-k] % MOD;
                    long long &ref = ndp[e+k][ns];
                    ref += add;
                    if(ref>=MOD) ref-=MOD;
                }
            }
            dp.swap(ndp);
        }

        long long ways = dp[ne][need];
        if(!ways) return 0;
        long long ans = ways * fact[ne] % MOD * fact[no] % MOD;
        return int(ans);
    }
};
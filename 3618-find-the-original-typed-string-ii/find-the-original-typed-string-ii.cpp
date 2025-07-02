const int MOD = 1000000007;
class Solution {
public:
    int possibleStringCount(string word, int k) {
        vector<int> lens;
        int n = word.size();
        for(int i=0,j;i<n;i=j){
            j=i+1;
            while(j<n && word[j]==word[i]) j++;
            lens.push_back(j-i);
        }
        int m = lens.size();
        long long P = 1;
        for(int x:lens) P = P * x % MOD;
        if(m >= k) return P;
        vector<int> dp(k), ndp(k), ps(k);
        dp[0] = 1;
        for(int len:lens){
            ps[0] = dp[0];
            for(int i=1;i<k;i++) ps[i] = (ps[i-1] + dp[i]) % MOD;
            ndp[0] = 0;
            for(int s=1;s<k;s++){
                int l = min(len, s);
                int res = ps[s-1];
                if(s-l-1 >= 0) res = (res - ps[s-l-1] + MOD) % MOD;
                ndp[s] = res;
            }
            swap(dp, ndp);
        }
        long long sum = 0;
        for(int i=0;i<k;i++) sum = (sum + dp[i]) % MOD;
        return (P - sum + MOD) % MOD;
    }
};
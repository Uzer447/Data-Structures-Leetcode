const long long MOD = 1000000007; 
class Solution {
public:
    int idealArrays(int n, int maxValue) {
        int M = maxValue;
        vector<vector<long long>> dp(2, vector<long long>(M+1,0));
        for (int i = 1; i <= M; i++) dp[1 % 2][i] = 1;
        vector<long long> ways;
        ways.push_back(0);
        long long tot = 0;
        for (int i = 1; i <= M; i++) tot = (tot + dp[1 % 2][i]) % MOD;
        ways.push_back(tot);
        int m = 1;
        while (true) {
            m++;
            int cur = m % 2, prev = (m - 1) % 2;
            for (int i = 1; i <= M; i++) dp[cur][i] = 0;
            for (int i = M; i >= 1; i--) {
                long long s = 0;
                for (int j = 2 * i; j <= M; j += i)
                    s = (s + dp[prev][j]) % MOD;
                dp[cur][i] = s;
            }
            tot = 0;
            for (int i = 1; i <= M; i++) tot = (tot + dp[cur][i]) % MOD;
            if (tot == 0) break;
            ways.push_back(tot);
        }
        int L = ways.size() - 1;
        long long ans = 0;
        for (int k = 1; k <= L; k++) {
            long long num = 1;
            for (int i = 0; i < k - 1; i++) num = (num * (n - 1 - i)) % MOD;
            long long den = 1;
            for (int i = 1; i < k; i++) den = (den * i) % MOD;
            long long inv = 1, power = MOD - 2, base = den;
            while (power) {
                if (power & 1) inv = (inv * base) % MOD;
                base = (base * base) % MOD;
                power >>= 1;
            }
            long long comb = (num * inv) % MOD;
            ans = (ans + ways[k] * comb) % MOD;
        }
        return ans;
    }
};
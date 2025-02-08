class Solution {
public:
    int numDecodings(string s) {
        const int MOD = 1e9 + 7;
        int n = s.size();
        if(n == 0) return 0;
        long dp0 = 1, dp1 = 0;
        auto ways1 = [](char ch) {
            if(ch == '*') return 9LL;
            else if(ch == '0') return 0LL;
            else return 1LL;
        };
        dp1 = ways1(s[0]) % MOD;
        for(int i = 1; i < n; ++i) {
            char c1 = s[i - 1], c2 = s[i];
            long w1 = ways1(c2) * dp1 % MOD;
            long w2 = 0;
            if(c1 == '*' && c2 == '*') {
                w2 = 15 * dp0 % MOD;
            }
            else if(c1 == '*') {
                if(c2 >= '0' && c2 <= '6') {
                    w2 = 2 * dp0 % MOD;
                }
                else if(c2 >= '7' && c2 <= '9') {
                    w2 = dp0 % MOD;
                }
            }
            else if(c2 == '*') {
                if(c1 == '1') {
                    w2 = 9 * dp0 % MOD;
                }
                else if(c1 == '2') {
                    w2 = 6 * dp0 % MOD;
                }
            }
            else {
                int num = (c1 - '0') * 10 + (c2 - '0');
                if(num >= 10 && num <= 26) {
                    w2 = dp0 % MOD;
                }
            }
            long dp2 = (w1 + w2) % MOD;
            dp0 = dp1;
            dp1 = dp2;
        }
        return dp1 % MOD;
    }
};
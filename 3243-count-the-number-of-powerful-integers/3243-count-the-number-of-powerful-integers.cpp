class Solution {
public:
    long long dp(const string &s, int pos, bool tight, int lim, vector<vector<long long>> &memo) {
        if(pos == s.size()) return 1;
        if(memo[pos][tight] != -1) return memo[pos][tight];
        int up = (tight ? s[pos]-'0' : lim);
        long long res = 0;
        for (int d = 0; d <= up && d <= lim; d++) {
            res += dp(s, pos+1, (tight && d==up), lim, memo);
        }
        memo[pos][tight] = res;
        return res;
    }
    long long countAllowed(long long N, int lim) {
        if(N < 0) return 0;
        string s = to_string(N);
        int n = s.size();
        vector<vector<long long>> memo(n, vector<long long>(2, -1));
        return dp(s, 0, true, lim, memo);
    }
    long long numAllowedInRange(long long L, long long R, int lim) {
        return countAllowed(R, lim) - countAllowed(L-1, lim);
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        long long t = stoll(s), M = 1;
        for (int i = 0; i < s.size(); i++) M *= 10;
        if(finish < t) return 0;
        long long b_min = (start <= t ? 0 : (start - t + M - 1) / M);
        long long b_max = (finish - t) / M;
        if(b_min > b_max) return 0;
        return numAllowedInRange(b_min, b_max, limit);
    }
};
 
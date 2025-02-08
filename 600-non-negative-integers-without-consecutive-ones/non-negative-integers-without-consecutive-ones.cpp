class Solution {
public:
    int findIntegers(int n) {
        vector<int> bits;
        while(n > 0) {
            bits.push_back(n & 1);
            n >>= 1;
        }
        reverse(bits.begin(), bits.end());
        memset(dp, -1, sizeof(dp));
        return dfs(0, 0, 1, bits);
    }
private:
    int dp[32][2][2];
    int dfs(int pos, int prev_bit, int tight, vector<int>& bits) {
        if (pos == bits.size()) return 1;
        if (dp[pos][prev_bit][tight] != -1) return dp[pos][prev_bit][tight];
        int limit = tight ? bits[pos] : 1;
        int res = 0;
        for (int cur = 0; cur <= limit; ++cur) {
            if (prev_bit == 1 && cur == 1) continue;
            res += dfs(pos + 1, cur, tight && (cur == limit), bits);
        }
        return dp[pos][prev_bit][tight] = res;
    }
};
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1'000'000'007;
        int cur[26], nxt[26];
        for (int i = 0; i < 26; ++i) cur[i] = 1;
        while (t--) {
            for (int i = 0; i < 25; ++i) nxt[i] = cur[i + 1];
            nxt[25] = (cur[0] + cur[1]) % MOD;
            memcpy(cur, nxt, sizeof cur);
        }
        long long ans = 0;
        for (char c : s) {
            ans += cur[c - 'a'];
            if (ans >= MOD) ans -= MOD;
        }
        return (int)ans;
    }
};
class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        auto f = [&](long long x) {
            int k = 0;
            while (x) {
                x >>= 2;
                ++k;
            }
            return (long long)k;
        };
        auto pref = [&](long long n) {
            if (n <= 0) return 0LL;
            long long res = 0, start = 1;
            int k = 1;
            while (start <= n) {
                long long end = min(n, start * 4 - 1);
                res += (end - start + 1) * 1LL * k;
                start *= 4;
                ++k;
            }
            return res;
        };
        long long ans = 0;
        for (auto& q : queries) {
            long long l = q[0], r = q[1];
            long long F = pref(r) - pref(l - 1);
            long long M = f(r);
            ans += max(M, (F + 1) / 2);
        }
        return ans;
    }
};
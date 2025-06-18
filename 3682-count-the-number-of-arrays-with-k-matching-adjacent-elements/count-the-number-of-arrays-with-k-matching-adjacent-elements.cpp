class Solution {
    static const long long MOD = 1000000007LL;
    long long mod_pow(long long a, long long e) {
        long long r = 1;
        while (e) {
            if (e & 1) r = r * a % MOD;
            a = a * a % MOD;
            e >>= 1;
        }
        return r;
    }
public:
    int countGoodArrays(int n, int m, int k) {
        if (m == 1) return k == n - 1 ? 1 : 0;
        vector<long long> fact(n + 1), invfact(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i % MOD;
        invfact[n] = mod_pow(fact[n], MOD - 2);
        for (int i = n; i >= 1; --i) invfact[i - 1] = invfact[i] * i % MOD;
        auto comb = [&](int N, int K) -> long long {
            if (K < 0 || K > N) return 0;
            return fact[N] * invfact[K] % MOD * invfact[N - K] % MOD;
        };
        long long ways = comb(n - 1, k);
        long long power = mod_pow(m - 1, n - k - 1);
        return (int)(ways * m % MOD * power % MOD);
    }
};
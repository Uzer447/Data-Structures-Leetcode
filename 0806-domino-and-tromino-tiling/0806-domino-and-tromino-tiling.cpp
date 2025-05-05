class Solution {
public:
    int numTilings(int n) {
        const long long mod = 1000000007;
        if (n == 0) return 1;
        if (n == 1) return 1;
        if (n == 2) return 2;
        long long a = 1, b = 1, c = 2;
        for (int i = 3; i <= n; ++i) {
            long long d = (2 * c % mod + a) % mod;
            a = b;
            b = c;
            c = d;
        }
        return c;
    }
};
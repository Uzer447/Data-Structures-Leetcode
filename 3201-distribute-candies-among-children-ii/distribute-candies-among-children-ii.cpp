class Solution {
public:
    long long distributeCandies(int n, int limit) {
        if (n > 3LL * limit)
            return 0;
        auto C2 = [](long long m) -> long long {
            return m >= 2 ? m * (m - 1) / 2 : 0;
        };
        const long long choose3[4] = {1, 3, 3, 1};
        long long res = 0;
        for (int k = 0; k < 4; ++k) {
            long long rem = n - 1LL * k * (limit + 1);
            long long term = C2(rem + 2);
            res += (k & 1 ? -1 : 1) * choose3[k] * term;
        }
        return res;
    }
};
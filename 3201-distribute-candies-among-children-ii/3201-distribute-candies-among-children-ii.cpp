class Solution {
public:
    long long distributeCandies(int n, int limit) {
        auto c2 = [](long long m) -> long long { return m >= 2 ? m * (m - 1) / 2 : 0; };
        const long long C[4] = {1, 3, 3, 1};
        long long ans = 0;
        for (int k = 0; k < 4; ++k) {
            long long rem = 1LL * n - 1LL * k * (limit + 1LL);
            long long term = c2(rem + 2);
            ans += (k & 1 ? -1 : 1) * C[k] * term;
        }
        return ans;
    }
};
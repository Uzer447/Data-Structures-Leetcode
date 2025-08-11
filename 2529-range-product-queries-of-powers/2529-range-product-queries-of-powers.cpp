class Solution {
    static constexpr long long MOD = 1'000'000'007LL;
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<long long> pow2;
        for (int b = 0, x = n; x; ++b, x >>= 1)
            if (x & 1) pow2.push_back(1LL << b);
        vector<int> res;
        res.reserve(queries.size());
        for (auto& q : queries) {
            long long cur = 1;
            for (int i = q[0]; i <= q[1]; ++i)
                cur = (cur * pow2[i]) % MOD;
            res.push_back((int)cur);
        }
        return res;
    }
};
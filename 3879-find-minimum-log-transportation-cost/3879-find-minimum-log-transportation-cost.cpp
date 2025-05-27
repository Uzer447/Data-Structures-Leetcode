class Solution {
public:
    long long minCost(int len, int k) {
        if (len <= k) return 0;
        if (len <= 2*k) return 1LL * (len - k) * k;
        // Cut off k, cost = k * (len-k)
        return 1LL * k * (len - k) + minCost(len - k, k);
    }
    long long minCuttingCost(int n, int m, int k) {
        return minCost(n, k) + minCost(m, k);
    }
};

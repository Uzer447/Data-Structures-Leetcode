class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int m = nums.size(), n = m / 3;
        vector<long long> pref(m), suff(m);
        priority_queue<int> pq1;
        long long sum1 = 0;
        for (int i = 0; i < m; ++i) {
            pq1.push(nums[i]);
            sum1 += nums[i];
            if (pq1.size() > n) {
                sum1 -= pq1.top();
                pq1.pop();
            }
            if (i >= n - 1) pref[i] = sum1;
        }
        priority_queue<int, vector<int>, greater<int>> pq2;
        long long sum2 = 0;
        for (int i = m - 1; i >= 0; --i) {
            pq2.push(nums[i]);
            sum2 += nums[i];
            if (pq2.size() > n) {
                sum2 -= pq2.top();
                pq2.pop();
            }
            if (i <= 2 * n) suff[i] = sum2;
        }
        long long ans = LLONG_MAX;
        for (int i = n - 1; i < 2 * n; ++i)
            ans = min(ans, pref[i] - suff[i + 1]);
        return ans;
    }
};
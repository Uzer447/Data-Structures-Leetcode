class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n), suffix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) prefix[i] = max(prefix[i-1], (long long)nums[i-1]);
        suffix[n-1] = nums[n-1];
        for (int i = n-2; i >= 0; i--) suffix[i] = max((long long)nums[i], suffix[i+1]);
        long long ans = 0;
        for (int j = 1; j <= n-2; j++) {
            long long diff = prefix[j] - nums[j];
            if(diff > 0) ans = max(ans, diff * suffix[j+1]);
        }
        return ans;
    }
};
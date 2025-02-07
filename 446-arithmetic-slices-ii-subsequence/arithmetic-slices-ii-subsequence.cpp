class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<long long, int>> dp(n);
        int total = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < i; ++j){
                long long diff = (long long)nums[i] - (long long)nums[j];
                int counts_at_j = dp[j][diff];
                dp[i][diff] += counts_at_j + 1;
                total += counts_at_j;
            }
        }
        return total;
    }
};
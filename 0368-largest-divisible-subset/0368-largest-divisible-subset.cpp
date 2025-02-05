class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1), hash(n);
        int lastIndex = 0;
        int maxi=1;
        for (int ind = 0; ind < n; ind++) {
            hash[ind] = ind;
            for (int j = 0; j < ind; j++) {
                if (nums[ind] % nums[j] == 0 && 1 + dp[j] > dp[ind]) {
                    dp[ind] = 1 + dp[j];
                    hash[ind] = j;
                }
            }
            if (dp[ind] > maxi) {
                maxi = dp[ind];
                lastIndex = ind;
            }
        }
        vector<int> ans;
        ans.push_back(nums[lastIndex]);
        while(hash[lastIndex]!=lastIndex)
        {
            lastIndex=hash[lastIndex];
            ans.push_back(nums[lastIndex]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
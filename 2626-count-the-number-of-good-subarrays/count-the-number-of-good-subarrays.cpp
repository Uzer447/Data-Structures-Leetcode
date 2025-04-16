class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0, pairs = 0;
        unordered_map<int,int> freq;
        int left = 0;
        for (int right = 0; right < n; right++) {
            pairs += freq[nums[right]];
            freq[nums[right]]++;
            while (left <= right && pairs >= k) {
                ans += (n - right);
                freq[nums[left]]--;
                pairs -= freq[nums[left]];
                left++;
            }
        }
        return ans;
    }
};
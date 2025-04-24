class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        int D = unordered_set<int>(nums.begin(), nums.end()).size();
        vector<int> cnt(2001);
        long long ans = 0;
        int l = 0, distinct = 0;
        for (int r = 0; r < n; ++r) {
            if (cnt[nums[r]]++ == 0) ++distinct;
            while (distinct == D) {
                ans += n - r;
                if (--cnt[nums[l]] == 0) --distinct;
                ++l;
            }
        }
        return (int)ans;
    }
};
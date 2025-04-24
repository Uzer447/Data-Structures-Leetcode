class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        int D = unordered_set<int>(nums.begin(), nums.end()).size();
        vector<int> freq(2001);
        long long res = 0;
        int l = 0, cur = 0;
        for (int r = 0; r < n; ++r) {
            if (freq[nums[r]]++ == 0) ++cur;
            while (cur == D) {
                res += n - r;
                if (--freq[nums[l]] == 0) --cur;
                ++l;
            }
        }
        return (int)res;
    }
};
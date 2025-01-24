class Solution {
public:
    int helper(vector<int>& nums, int goal) {
        int n = nums.size();
        int l = 0, r = 0, cnt = 0;
        map<int, int> mp;
        while (r < n) {
            mp[nums[r]]++;
            while (mp.size() > goal) {
                mp[nums[l]]--;
                if (mp[nums[l]] == 0)
                    mp.erase(nums[l]);
                l++;
            }
            cnt += r - l + 1;
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k - 1);
    }
};
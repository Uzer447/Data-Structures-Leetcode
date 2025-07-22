class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> s;
        long long cur = 0, best = 0;
        int l = 0;
        for (int r = 0; r < nums.size(); ++r) {
            while (s.count(nums[r])) {
                s.erase(nums[l]);
                cur -= nums[l];
                ++l;
            }
            s.insert(nums[r]);
            cur += nums[r];
            best = max(best, cur);
        }
        return (int)best;
    }
};
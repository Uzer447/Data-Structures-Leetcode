class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        auto countPairs = [&](int T) -> long long {
            long long cnt = 0;
            int l = 0, r = nums.size() - 1;
            while(l < r){
                if((long long)nums[l] + nums[r] <= T){
                    cnt += (r - l);
                    l++;
                } else {
                    r--;
                }
            }
            return cnt;
        };
        return countPairs(upper) - countPairs(lower - 1);
    }
};
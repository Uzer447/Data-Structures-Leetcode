class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        if (!p) return 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        auto ok = [&](int x) {
            int c = 0;
            for (int i = 0; i + 1 < n && c < p;) {
                if (nums[i + 1] - nums[i] <= x) { ++c; i += 2; }
                else ++i;
            }
            return c >= p;
        };
        int lo = 0, hi = nums.back() - nums.front();
        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);
            ok(mid) ? hi = mid : lo = mid + 1;
        }
        return lo;
    }
};
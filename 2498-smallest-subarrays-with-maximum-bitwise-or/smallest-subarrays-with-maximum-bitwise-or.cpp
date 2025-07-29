class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> last(31, -1), res(n);
        int suf = 0;
        for (int i = n - 1; i >= 0; --i) {
            suf |= nums[i];
            for (int b = 0; b < 31; ++b)
                if (nums[i] >> b & 1) last[b] = i;
            int j = i;
            for (int b = 0; b < 31; ++b)
                if (suf >> b & 1) j = max(j, last[b]);
            res[i] = j - i + 1;
        }
        return res;
    }
};
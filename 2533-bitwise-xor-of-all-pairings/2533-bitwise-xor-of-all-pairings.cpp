class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int x1 = 0, x2 = 0;
        for (int num : nums1) x1 ^= num;
        for (int num : nums2) x2 ^= num;
        int res = 0;
        if (nums2.size() % 2) res ^= x1;
        if (nums1.size() % 2) res ^= x2;
        return res;
    }
};
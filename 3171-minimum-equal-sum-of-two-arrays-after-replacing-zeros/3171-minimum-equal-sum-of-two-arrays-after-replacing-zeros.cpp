class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long s1 = 0, s2 = 0, z1 = 0, z2 = 0;
        for (int x : nums1) x ? s1 += x : ++z1;
        for (int x : nums2) x ? s2 += x : ++z2;

        if (!z1 && !z2) return s1 == s2 ? s1 : -1;
        if (!z1) return s1 - s2 >= z2 ? s1 : -1;
        if (!z2) return s2 - s1 >= z1 ? s2 : -1;

        long long diff = s1 - s2;
        long long k = z2 - z1 - diff;
        return k >= 0 ? s2 + z2 : s1 + z1;
    }
};
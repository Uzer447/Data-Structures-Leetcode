class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size(), result = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                if (nums1[i] == nums2[j] &&
                    (i == 0 || j == 0 || nums1[i - 1] != nums2[j - 1])) {
                    int subResult = 1;
                    while (subResult + i < n && subResult + j < m &&
                           nums1[subResult + i] == nums2[subResult + j])
                        ++subResult;
                    result = max(result, subResult);
                }
            }
        return result;
    }
};
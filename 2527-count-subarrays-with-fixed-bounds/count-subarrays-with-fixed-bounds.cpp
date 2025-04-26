class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long res = 0;
        int lastMin = -1, lastMax = -1, lastBad = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == minK) lastMin = i;
            if (nums[i] == maxK) lastMax = i;
            if (nums[i] < minK || nums[i] > maxK) lastBad = i;
            int left = min(lastMin, lastMax);
            if (left > lastBad) res += left - lastBad;
        }
        return res;
    }
};
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long base = 0, posSum = 0, minPos = LLONG_MAX, maxNonPos = LLONG_MIN;
        int posCnt = 0;
        for (int v : nums) {
            long long d = (v ^ k) - v;
            base += v;
            if (d > 0) {
                posSum += d;
                ++posCnt;
                minPos = min(minPos, d);
            } else {
                maxNonPos = max(maxNonPos, d);
            }
        }
        if (!(posCnt & 1)) return base + posSum;
        long long gain1 = posSum - minPos;
        long long gain2 = maxNonPos == LLONG_MIN ? LLONG_MIN : posSum + maxNonPos;
        return base + max(gain1, gain2);
    }
};
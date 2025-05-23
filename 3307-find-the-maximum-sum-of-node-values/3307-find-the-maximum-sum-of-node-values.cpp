class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long base = 0, sumPos = 0, minPos = LLONG_MAX, maxNonPos = LLONG_MIN;
        int cntPos = 0;
        for (int x : nums) {
            long long d = (x ^ k) - x;
            base += x;
            if (d > 0) {
                sumPos += d;
                cntPos++;
                minPos = min(minPos, d);
            } else {
                maxNonPos = max(maxNonPos, d);
            }
        }
        if (cntPos % 2 == 0) return base + sumPos;
        long long gainA = sumPos - minPos;
        long long gainB = maxNonPos == LLONG_MIN ? LLONG_MIN : sumPos + maxNonPos;
        return base + max(gainA, gainB);
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        vector<int> indices(k, 0);
        vector<int> range = {0, INT_MAX};

        while (true) {
            int curMin = INT_MAX, curMax = INT_MIN, minListIndex = 0;
            for (int i = 0; i < k; i++) {
                int currentElement = nums[i][indices[i]];
                if (currentElement < curMin) {
                    curMin = currentElement;
                    minListIndex = i;
                }
                if (currentElement > curMax) {
                    curMax = currentElement;
                }
            }
            if (curMax - curMin < range[1] - range[0]) {
                range[0] = curMin;
                range[1] = curMax;
            }
            if (++indices[minListIndex] == nums[minListIndex].size()) break;
        }

        return range;
    }
};
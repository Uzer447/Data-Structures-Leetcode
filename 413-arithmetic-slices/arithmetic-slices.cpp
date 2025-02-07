class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(), i = 0, res = 0;

        while (i <= n - 3) {
            if ((nums[i + 2] - nums[i + 1]) == (nums[i + 1] - nums[i])) {
                int j = i + 3, prev = nums[i + 2];

                while (j < n &&
                       (nums[j] - prev) == (nums[i + 2] - nums[i + 1])) {
                    prev = nums[j];
                    j++;
                }

                res = res + ((j - i - 2) * (j - i - 1)) / 2;

                i = j - 1;
            } else {
                i++;
            }
        }

        return res;
    }
};
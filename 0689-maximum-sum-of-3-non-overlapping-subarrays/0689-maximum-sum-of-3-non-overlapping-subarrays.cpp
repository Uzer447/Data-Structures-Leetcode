class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> total(n - k + 1);
        int window_sum = 0;
        for (int i = 0; i < k; ++i) {
            window_sum += nums[i];
        }
        total[0] = window_sum;
        for (int i = 1; i <= n - k; ++i) {
            window_sum += nums[i + k - 1] - nums[i - 1];
            total[i] = window_sum;
        }
        vector<int> left(n - k + 1);
        int max_index = 0;
        for (int i = 0; i <= n - k; ++i) {
            if (total[i] > total[max_index]) {
                max_index = i;
            }
            left[i] = max_index;
        }
        vector<int> right(n - k + 1);
        max_index = n - k;
        right[n - k] = n - k;
        for (int i = n - k - 1; i >= 0; --i) {
            if (total[i] >= total[max_index]) {
                max_index = i;
            }
            right[i] = max_index;
        }
        int max_sum = -1;
        vector<int> result(3, -1);
        for (int j = k; j <= n - 2 * k; ++j) {
            int i = left[j - k];
            int l = right[j + k];
            int current_sum = total[i] + total[j] + total[l];
            if (current_sum > max_sum) {
                max_sum = current_sum;
                result = {i, j, l};
            } else if (current_sum == max_sum) {
                if (vector<int>{i, j, l} < result) {
                    result = {i, j, l};
                }
            }
        }
        return result;
    }
};
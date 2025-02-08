class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> w;
        int sum = accumulate(nums.begin(), nums.begin() + k, 0);
        w.push_back(sum);
        for (int i = k; i < n; ++i) {
            sum += nums[i] - nums[i - k];
            w.push_back(sum);
        }
        int m = w.size();
        vector<int> left(m), right(m);
        int best = 0;
        for (int i = 0; i < m; ++i) {
            if (w[i] > w[best]) best = i;
            left[i] = best;
        }
        best = m - 1;
        for (int i = m - 1; i >= 0; --i) {
            if (w[i] >= w[best]) best = i;
            right[i] = best;
        }
        int maxsum = 0;
        vector<int> res(3);
        for (int j = k; j < m - k; ++j) {
            int i = left[j - k];
            int l = right[j + k];
            int total = w[i] + w[j] + w[l];
            if (total > maxsum) {
                maxsum = total;
                res = {i, j, l};
            } else if (total == maxsum) {
                vector<int> tmp = {i, j, l};
                if (tmp < res) res = tmp;
            }
        }
        return res;
    }
};
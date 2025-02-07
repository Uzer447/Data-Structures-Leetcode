class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> sums(n + 1, 0);
        for (int i = 0; i < n; ++i)
            sums[i + 1] = sums[i] + nums[i];
        return countWhileMerge(sums, 0, n + 1, lower, upper);
    }
private:
    int countWhileMerge(vector<long long>& sums, int start, int end, int lower, int upper) {
        if (end - start <= 1) return 0;
        int mid = (start + end) / 2;
        int count = countWhileMerge(sums, start, mid, lower, upper)
                  + countWhileMerge(sums, mid, end, lower, upper);
        int j = mid, k = mid;
        for (int i = start; i < mid; ++i) {
            while (k < end && sums[k] - sums[i] < lower) ++k;
            while (j < end && sums[j] - sums[i] <= upper) ++j;
            count += j - k;
        }
        vector<long long> sorted(end - start);
        int p = start, q = mid, idx = 0;
        while (p < mid && q < end) {
            if (sums[p] <= sums[q])
                sorted[idx++] = sums[p++];
            else
                sorted[idx++] = sums[q++];
        }
        while (p < mid)
            sorted[idx++] = sums[p++];
        while (q < end)
            sorted[idx++] = sums[q++];
        for (int i = 0; i < idx; ++i)
            sums[start + i] = sorted[i];
        return count;
    }
};
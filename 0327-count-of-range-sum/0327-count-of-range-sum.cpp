class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long long> sums(nums.size()+1, 0);
        for (int i = 0; i < nums.size(); ++i)
            sums[i+1] = sums[i] + nums[i];
        return countWhileMergeSort(sums, 0, sums.size(), lower, upper);
    }
    
    int countWhileMergeSort(vector<long long>& sums, int start, int end, int lower, int upper) {
        if (end - start <= 1) return 0;
        int mid = (start + end) / 2;
        int count = countWhileMergeSort(sums, start, mid, lower, upper) + 
                    countWhileMergeSort(sums, mid, end, lower, upper);
        int j = mid, k = mid, t = mid;
        vector<long long> cache(end - start, 0);
        for (int i = start, r = 0; i < mid; ++i) {
            while (k < end && sums[k] - sums[i] < lower) ++k;
            while (j < end && sums[j] - sums[i] <= upper) ++j;
            count += j - k;
            while (t < end && sums[t] < sums[i]) cache[r++] = sums[t++];
            cache[r++] = sums[i];
        }
        copy(cache.begin(), cache.begin() + t - start, sums.begin() + start);
        return count;
    }
};
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size(), chunks = 0;
        vector<int> sorted_arr = arr;
        sort(sorted_arr.begin(), sorted_arr.end());
        map<int, int> count_arr, count_sorted;
        for (int i = 0; i < n; ++i) {
            ++count_arr[arr[i]];
            ++count_sorted[sorted_arr[i]];
            if (count_arr == count_sorted) ++chunks;
        }
        return chunks;
    }
};
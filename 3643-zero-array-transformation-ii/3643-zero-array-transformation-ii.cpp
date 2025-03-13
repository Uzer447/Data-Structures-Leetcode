#include <vector>
using namespace std;
 
class Solution {
public:
    bool possible(int k, const vector<int>& nums, const vector<vector<int>>& queries) {
        int n = nums.size();
        vector<long long> diff(n + 1, 0);
        for (int i = 0; i < k; i++) {
            diff[queries[i][0]] += queries[i][2];
            if (queries[i][1] + 1 < n) diff[queries[i][1] + 1] -= queries[i][2];
        }
        long long cur = 0;
        for (int i = 0; i < n; i++) {
            cur += diff[i];
            if (cur < nums[i]) return false;
        }
        return true;
    }
 
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int q = queries.size();
        int low = 0, high = q + 1, ans = -1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (possible(mid, nums, queries)) {
                ans = mid;
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return (ans == -1 || ans > q) ? -1 : ans;
    }
};
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<char> mark(n, 0);
        for (int i = 0; i < n; ++i) if (nums[i] == key) {
            int l = max(0, i - k), r = min(n - 1, i + k);
            for (int j = l; j <= r; ++j) mark[j] = 1;
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) if (mark[i]) ans.push_back(i);
        return ans;
    }
};
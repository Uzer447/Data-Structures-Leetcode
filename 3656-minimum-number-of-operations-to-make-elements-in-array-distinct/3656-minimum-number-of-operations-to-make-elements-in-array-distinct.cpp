class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        for (int k = 0; ; k++) {
            int start = 3 * k;
            if (start >= n) return k;
            unordered_set<int> s;
            bool ok = true;
            for (int i = start; i < n; i++) {
                if (s.count(nums[i])) { ok = false; break; }
                s.insert(nums[i]);
            }
            if (ok) return k;
        }
    }
};
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        bool seen[105] = {0};
        int cnt = 0;
        for (int x : nums) {
            if (x < k) return -1;
            if (x > k && !seen[x]) {
                seen[x] = true;
                cnt++;
            }
        }
        return cnt;
    }
};
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n + 1);
        for (auto& q : queries) 
        {
            ++diff[q[0]];
            if (q[1] + 1 < n) --diff[q[1] + 1];
        }
        long long temp = 0;
        for (int i = 0; i < n; i++) 
        {
            temp += diff[i];
            if (nums[i]-temp > 0) return false;
        }
        return true;
    }
};
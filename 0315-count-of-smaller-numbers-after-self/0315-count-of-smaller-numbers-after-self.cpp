class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts(n);
        int offset = 10000;
        int size = 2 * 10000 + 2;
        vector<int> BIT(size, 0);
        auto update = [&](int index) {
            while (index < size) {
                BIT[index] += 1;
                index += index & -index;
            }
        };
        auto query = [&](int index) {
            int res = 0;
            while (index > 0) {
                res += BIT[index];
                index -= index & -index;
            }
            return res;
        };
        for (int i = n - 1; i >= 0; --i) {
            int index = nums[i] + offset + 1;
            counts[i] = query(index - 1);
            update(index);
        }
        return counts;
    }
};
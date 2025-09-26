class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            int large = nums[i];
            int ptr1 = 0, ptr2 = i - 1;
            if (ptr1 == ptr2 || ptr2 < 0)
                return res;
            while (ptr1 < ptr2) {
                int curr = nums[ptr1] + nums[ptr2];
                if (curr > large) {
                    res = res + ptr2 - ptr1;
                    ptr2--;
                } else if (curr <= large) {
                    ptr1++;
                }
            }
        }
        return res;
    }
};
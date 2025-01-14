class Solution {
public:
    vector<int> pickMax(vector<int>& nums, int k) {
        vector<int> stack;
        int drop = nums.size() - k;
        for (int num : nums) {
            while (drop && !stack.empty() && stack.back() < num) {
                stack.pop_back();
                drop--;
            }
            stack.push_back(num);
        }
        stack.resize(k);
        return stack;
    }
    
    bool greater(vector<int>& nums1, int i, vector<int>& nums2, int j) {
        while (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]) {
            i++;
            j++;
        }
        return j == nums2.size() || (i < nums1.size() && nums1[i] > nums2[j]);
    }
    
    vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int i = 0, j = 0;
        while (i < nums1.size() || j < nums2.size()) {
            if (greater(nums1, i, nums2, j))
                ans.push_back(nums1[i++]);
            else
                ans.push_back(nums2[j++]);
        }
        return ans;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> max_num(k, 0);
        int m = nums1.size(), n = nums2.size();
        int start = max(0, k - n), end = min(k, m);
        for (int i = start; i <= end; ++i) {
            vector<int> max_subseq1 = pickMax(nums1, i);
            vector<int> max_subseq2 = pickMax(nums2, k - i);
            vector<int> candidate = merge(max_subseq1, max_subseq2);
            if (candidate > max_num)
                max_num = candidate;
        }
        return max_num;
    }
};
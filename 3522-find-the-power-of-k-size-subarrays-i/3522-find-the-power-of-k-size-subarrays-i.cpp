class Solution {
public:
    bool isConsecutive(vector<int> temp) {
        for (int i = 0; i < temp.size() - 1; i++) {
            if (temp[i + 1] - temp[i] != 1) {
                return false;
            }
        }
        return true;
    }
    bool isSorted(vector<int> temp) {
        for (int i = 0; i < temp.size() - 1; i++) {
            if (temp[i + 1] < temp[i]) {
                return false;
            }
        }
        return true;
    }
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n-k+1; i++) {
            vector<int> temp;
            for (int j = 0; j < k; j++) {
                temp.push_back(nums[i + j]);
            }
            if (isConsecutive(temp) && isSorted(temp)) {
                ans.push_back(temp.back());
            } else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
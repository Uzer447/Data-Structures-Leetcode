class Solution {
public:
    void solve(int ind, set<vector<int>>& ans, vector<int>& temp, int target,
               vector<int>& nums) {
        if (target == 0) {
            sort(temp.begin(), temp.end());
            ans.insert(temp);
            return;
        }
        for (int i = ind; i < nums.size(); i++) {
            if (i > ind && nums[i] == nums[i-1])
                continue;
            if (nums[ind] > target)
                break;
            temp.push_back(nums[i]);
            solve(i + 1, ans, temp, target - nums[i], nums);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        set<vector<int>> ans;
        vector<int> temp;
        solve(0, ans, temp, target, candidates);
        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
    }
};
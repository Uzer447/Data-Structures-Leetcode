class Solution {
public:
    void func(int ind, int target, vector<int> &nums,set<vector<int>>& ans, vector<int>& temp) {
        if (ind == nums.size()) {
            if (target == 0) {
                ans.insert(temp);
            }
            return;
        }
        func(ind+1,target,nums,ans,temp);
        if(nums[ind]<=target)
        {
            temp.push_back(nums[ind]);
            func(ind,target-nums[ind],nums,ans,temp);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> ans;
        vector<int> temp;
        func(0,target,candidates,ans,temp);
        vector<vector<int>> res(ans.begin(),ans.end());
        return res;
    }
};
class Solution {
public:
    void combsum(vector<vector<int>> &res,vector<int> &ds,vector<int> &candidates,int ind,int target)
    {
        if(target==0)
        {
            res.push_back(ds);
            return;
        }
        for(int i=ind;i<candidates.size() && target>=candidates[i];i++)
        {
            if(i==ind || candidates[i]!=candidates[i-1])
            {
                ds.push_back(candidates[i]);
                combsum(res,ds,candidates,i+1,target-candidates[i]);
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ds;
        sort(candidates.begin(),candidates.end());
        combsum(res,ds,candidates,0,target);
        return res;
    }
};
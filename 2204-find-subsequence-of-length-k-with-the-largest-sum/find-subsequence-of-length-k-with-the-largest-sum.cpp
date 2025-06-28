class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>> v;
        v.reserve(nums.size());
        for (int i = 0; i < nums.size(); ++i) v.push_back({nums[i], i});
        nth_element(v.begin(), v.begin() + k, v.end(), [](auto& a, auto& b) { return a.first > b.first; });
        v.resize(k);
        sort(v.begin(), v.end(), [](auto& a, auto& b) { return a.second < b.second; });
        vector<int> ans;
        ans.reserve(k);
        for (auto& p : v) ans.push_back(p.first);
        return ans;
    }
};
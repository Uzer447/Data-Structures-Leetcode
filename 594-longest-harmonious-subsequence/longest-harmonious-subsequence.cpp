class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<long long,int> mp;
        for (long long x : nums) ++mp[x];
        long long res = 0;
        for (auto& [k, v] : mp) {
            if (mp.count(k + 1)) res = max(res, (long long)v + mp[k + 1]);
        }
        return (int)res;
    }
};
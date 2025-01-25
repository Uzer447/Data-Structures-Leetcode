class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int,int>> num_idx(n);
        for(int i = 0; i < n; ++i) num_idx[i] = {nums[i], i};
        sort(num_idx.begin(), num_idx.end());
        vector<int> parent(n);
        for(int i = 0; i < n; ++i) parent[i] = i;
        function<int(int)> find = [&](int x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        };
        auto unite = [&](int x, int y) {
            int fx = find(x), fy = find(y);
            if(fx != fy) parent[fy] = fx;
        };
        for(int i = 0; i < n - 1; ++i) {
            int val1 = num_idx[i].first, idx1 = num_idx[i].second;
            int val2 = num_idx[i+1].first, idx2 = num_idx[i+1].second;
            if(val2 - val1 <= limit) unite(idx1, idx2);
        }
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; ++i) {
            int root = find(i);
            mp[root].push_back(i);
        }
        vector<int> res(n);
        for(auto& p : mp) {
            vector<int> idxs = p.second;
            vector<int> vals;
            for(int idx : idxs) vals.push_back(nums[idx]);
            sort(idxs.begin(), idxs.end());
            sort(vals.begin(), vals.end());
            for(int i = 0; i < idxs.size(); ++i) res[idxs[i]] = vals[i];
        }
        return res;
    }
};
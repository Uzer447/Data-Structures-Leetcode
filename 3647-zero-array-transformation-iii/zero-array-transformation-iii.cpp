class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        vector<pair<int,int>> seg(m);
        for (int i = 0; i < m; ++i) seg[i] = {queries[i][0], queries[i][1]};
        sort(seg.begin(), seg.end());
        priority_queue<int> cand;
        priority_queue<int, vector<int>, greater<int>> in;
        int ptr = 0, used = 0;
        for (int i = 0; i < n; ++i) {
            while (ptr < m && seg[ptr].first <= i) cand.push(seg[ptr++].second);
            while (!in.empty() && in.top() < i) in.pop();
            while (!cand.empty() && cand.top() < i) cand.pop();
            int need = nums[i] - (int)in.size();
            while (need > 0) {
                while (!cand.empty() && cand.top() < i) cand.pop();
                if (cand.empty()) return -1;
                in.push(cand.top());
                cand.pop();
                ++used;
                --need;
            }
        }
        return m - used;
    }
};
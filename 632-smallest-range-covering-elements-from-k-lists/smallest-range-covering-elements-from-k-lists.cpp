class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        typedef pair<int, pair<int, int>> Node;
        priority_queue<Node, vector<Node>, greater<Node>> pq;
        int current_max = INT_MIN;
        for(int i = 0; i < k; ++i) {
            pq.push({nums[i][0], {i, 0}});
            current_max = max(current_max, nums[i][0]);
        }
        int range_start = 0, range_end = INT_MAX;
        while(true) {
            auto [min_value, idxs] = pq.top();
            pq.pop();
            int list_idx = idxs.first, elem_idx = idxs.second;
            if(current_max - min_value < range_end - range_start || 
               (current_max - min_value == range_end - range_start && min_value < range_start)) {
                range_start = min_value;
                range_end = current_max;
            }
            if(elem_idx + 1 < nums[list_idx].size()) {
                int next_value = nums[list_idx][elem_idx + 1];
                pq.push({next_value, {list_idx, elem_idx + 1}});
                current_max = max(current_max, next_value);
            } else {
                break;
            }
        }
        return {range_start, range_end};
    }
};
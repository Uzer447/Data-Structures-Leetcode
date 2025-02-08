class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int n = positions.size(), maxH = 0;
        vector<int> ans(n);
        vector<pair<pair<int, int>, int>> intervals;
        for (int i = 0; i < n; ++i) {
            int left = positions[i][0], size = positions[i][1], right = left + size, height = size;
            for (auto& pr : intervals) {
                int l = pr.first.first, r = pr.first.second;
                if (left < r && l < right) height = max(height, pr.second + size);
            }
            intervals.push_back({{left, right}, height});
            maxH = max(maxH, height);
            ans[i] = maxH;
        }
        return ans;
    }
};
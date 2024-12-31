class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        for (int axis = 0; axis <= 1; ++axis) {
            vector<pair<int, int>> intervals;
            for (const auto& rect : rectangles) {
                int start = rect[axis];
                int end = rect[axis + 2];
                intervals.emplace_back(start, end);
            }
            sort(intervals.begin(), intervals.end());
            vector<pair<int, int>> merged;
            for (const auto& interval : intervals) {
                int start = interval.first;
                int end = interval.second;
                if (merged.empty() || merged.back().second <= start) {
                    merged.emplace_back(start, end);
                } else {
                    merged.back().second = max(merged.back().second, end);
                }
            }
            if (merged.size() >= 3) {
                return true;
            }
        }
        return false;
    }
};
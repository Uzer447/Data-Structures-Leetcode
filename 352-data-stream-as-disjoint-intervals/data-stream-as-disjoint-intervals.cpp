class SummaryRanges {
public:
    set<pair<int, int>> intervals;
    SummaryRanges() {
    }
    void addNum(int val) {
        int start = val, end = val;
        auto it = intervals.lower_bound({val, val});
        if (it != intervals.begin()) {
            auto prev = it;
            --prev;
            if (prev->second + 1 >= val) {
                start = prev->first;
                end = max(end, prev->second);
                intervals.erase(prev);
            }
        }
        while (it != intervals.end() && it->first <= end + 1) {
            end = max(end, it->second);
            intervals.erase(it++);
        }
        intervals.insert({start, end});
    }
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for (auto& interval : intervals) {
            res.push_back({interval.first, interval.second});
        }
        return res;
    }
};
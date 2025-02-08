class RangeModule {
    map<int, int> intervals;
public:
    RangeModule() {}

    void addRange(int left, int right) {
        int l = left, r = right;
        auto it = intervals.lower_bound(l);
        if (it != intervals.begin()) {
            --it;
            if (it->second < l) ++it;
        }
        while (it != intervals.end() && it->first <= r) {
            l = min(l, it->first);
            r = max(r, it->second);
            it = intervals.erase(it);
        }
        intervals[l] = r;
    }

    bool queryRange(int left, int right) {
        if (left >= right) return true;
        auto it = intervals.upper_bound(left);
        if (it == intervals.begin()) return false;
        --it;
        return it->first <= left && right <= it->second;
    }

    void removeRange(int left, int right) {
        if (left >= right) return;
        auto it = intervals.lower_bound(left);
        if (it != intervals.begin()) {
            --it;
            if (it->second <= left) ++it;
        }
        vector<pair<int, int>> temp;
        while (it != intervals.end() && it->first < right) {
            int l = it->first, r = it->second;
            if (l < left) temp.push_back({l, left});
            if (r > right) temp.push_back({right, r});
            it = intervals.erase(it);
        }
        for (auto &p : temp) intervals[p.first] = p.second;
    }
};
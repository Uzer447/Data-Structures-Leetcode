class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> events;
        for (auto& b : buildings) {
            events.emplace_back(b[0], b[2]);
            events.emplace_back(b[1], -b[2]);
        }
        sort(events.begin(), events.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
            if (a.first != b.first) return a.first < b.first;
            else return a.second > b.second;
        });
        multiset<int> heights = {0};
        int prev = 0;
        vector<vector<int>> res;
        for (auto& e : events) {
            int x = e.first, h = e.second;
            if (h > 0) heights.insert(h);
            else heights.erase(heights.find(-h));
            int cur = *heights.rbegin();
            if (cur != prev) {
                res.push_back({x, cur});
                prev = cur;
            }
        }
        return res;
    }
};
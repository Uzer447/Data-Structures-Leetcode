class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b){ return a[0] < b[0]; });
        priority_queue<int, vector<int>, greater<int>> pq;
        int i = 0, n = events.size(), day = 0, ans = 0;
        while (i < n || !pq.empty()) {
            if (pq.empty()) day = events[i][0];
            while (i < n && events[i][0] <= day) pq.push(events[i++][1]);
            while (!pq.empty() && pq.top() < day) pq.pop();
            if (!pq.empty()) {
                pq.pop();
                ++ans;
                ++day;
            }
        }
        return ans;
    }
};
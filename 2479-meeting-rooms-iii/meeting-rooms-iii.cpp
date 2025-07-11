
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<int> cnt(n);
        priority_queue<int, vector<int>, greater<int>> freeRooms;
        for (int i = 0; i < n; ++i) freeRooms.push(i);
        using pll = pair<long long, int>;
        priority_queue<pll, vector<pll>, greater<pll>> busy;
        for (auto& m : meetings) {
            long long s = m[0], e = m[1], d = e - s;
            while (!busy.empty() && busy.top().first <= s) {
                freeRooms.push(busy.top().second);
                busy.pop();
            }
            if (!freeRooms.empty()) {
                int room = freeRooms.top();
                freeRooms.pop();
                busy.push({s + d, room});
                ++cnt[room];
            } else {
                auto [t, room] = busy.top();
                busy.pop();
                busy.push({t + d, room});
                ++cnt[room];
            }
        }
        int best = 0;
        for (int i = 1; i < n; ++i) if (cnt[i] > cnt[best]) best = i;
        return best;
    }
};
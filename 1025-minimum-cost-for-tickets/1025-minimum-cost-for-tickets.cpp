class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> travel_days(days.begin(), days.end());
        int last_day = days.back();
        vector<int> dp(last_day + 31, 0);
        for (int day = 1; day <= last_day; ++day) {
            if (travel_days.find(day) == travel_days.end()) {
                dp[day] = dp[day - 1];
            } else {
                dp[day] = min({
                    dp[day - 1] + costs[0],  
                    dp[max(0, day - 7)] + costs[1],  
                    dp[max(0, day - 30)] + costs[2]
                });
            }
        }
        return dp[last_day];
    }
};
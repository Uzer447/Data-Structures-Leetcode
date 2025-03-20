#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<tuple<int, int, int>> jobs;
        for (int i = 0; i < n; i++) jobs.emplace_back(startTime[i], endTime[i], profit[i]);
        sort(jobs.begin(), jobs.end(), [](auto &a, auto &b) { return get<1>(a) < get<1>(b); });
        vector<int> ends(n);
        for (int i = 0; i < n; i++) ends[i] = get<1>(jobs[i]);
        vector<long long> dp(n);
        dp[0] = get<2>(jobs[0]);
        for (int i = 1; i < n; i++) {
            int s = get<0>(jobs[i]);
            int p = get<2>(jobs[i]);
            int idx = upper_bound(ends.begin(), ends.end(), s) - ends.begin() - 1;
            long long incl = p;
            if (idx >= 0) incl += dp[idx];
            dp[i] = max(dp[i - 1], incl);
        }
        return dp[n - 1];
    }
};
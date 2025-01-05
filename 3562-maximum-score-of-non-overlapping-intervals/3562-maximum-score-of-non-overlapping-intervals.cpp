class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> arr(n);
        for(int i = 0; i < n; ++i) {
            arr[i] = intervals[i];
            arr[i].push_back(i);
        }
        sort(arr.begin(), arr.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        vector<int> ends(n);
        for(int i = 0; i < n; ++i) ends[i] = arr[i][1];
        vector<vector<pair<long long, vector<int>>>> dp(n+1, vector<pair<long long, vector<int>>>(5, {0LL, {}}));
        for(int i = 1; i <= n; ++i) {
            int li = arr[i-1][0], wi = arr[i-1][2], idx = arr[i-1][3];
            for(int k = 1; k <= 4; ++k) {
                dp[i][k] = dp[i-1][k];
                int p = lower_bound(ends.begin(), ends.end(), li) - ends.begin() - 1;
                if(k >= 1) {
                    long long cw = (p >= 0 ? dp[p+1][k-1].first : 0LL) + wi;
                    vector<int> ci = (p >= 0 ? dp[p+1][k-1].second : vector<int>());
                    ci.insert(lower_bound(ci.begin(), ci.end(), idx), idx);
                    if(cw > dp[i][k].first || (cw == dp[i][k].first && ci < dp[i][k].second)) {
                        dp[i][k] = {cw, ci};
                    }
                }
            }
        }
        long long resw = -1;
        vector<int> resi;
        for(int k = 1; k <= 4; ++k) {
            long long w = dp[n][k].first;
            vector<int>& ind = dp[n][k].second;
            if(w > resw || (w == resw && ind < resi)) {
                resw = w;
                resi = ind;
            }
        }
        return resi;
    }
};
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> ans(n);
        vector<pair<int,int>> vp;
        for(int i = 0; i < n; i++) {
            vp.push_back({intervals[i][0],i});
        }
        sort(vp.begin(), vp.end());
        for(int i = 0; i < n; i++) {
            int target = intervals[i][1];
            int s = 0, e = n-1;
            int potentialAns = INT_MIN;
            while(s <= e) {
                int m = s + (e-s) / 2;
                if(vp[m].first < target) {
                    s = m+1;
                }
                else {
                    potentialAns = vp[m].second;
                    e = m-1;
                }
            }
            ans[i] = (potentialAns != INT_MIN) ? potentialAns : -1;
        }
        return ans;
    }
};
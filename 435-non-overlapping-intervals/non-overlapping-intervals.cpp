class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b)
    {
        if(a[1]<b[1])
        return true;
        return false;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int cnt=0;
        int free=0;
        cnt=1;
        free=intervals[0][1];
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]>=free)
            {
                cnt++;
                free=intervals[i][1];
            }
        }
        return intervals.size()-cnt;
    }
};
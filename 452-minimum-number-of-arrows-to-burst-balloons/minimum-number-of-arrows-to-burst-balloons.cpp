class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int cnt=1;
        int laste=points[0][1];
       int n=points.size();
        for (int i=1;i<n;i++){
                   
                   if (laste<points[i][0]){
                    cnt++;
                    laste=points[i][1];
                   }
                   else laste=min(laste,points[i][1]);
        }
        return cnt;

    }
};
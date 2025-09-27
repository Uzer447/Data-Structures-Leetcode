class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                for (int k = j + 1; k < n; ++k) {
                    long long x1 = points[i][0], y1 = points[i][1];
                    long long x2 = points[j][0], y2 = points[j][1];
                    long long x3 = points[k][0], y3 = points[k][1];
                    long long twice = llabs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
                    ans = max(ans, twice / 2.0);
                }
        return ans;
    }
};
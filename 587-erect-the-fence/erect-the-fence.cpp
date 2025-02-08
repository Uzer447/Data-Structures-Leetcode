class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 1)
            return points;
        sort(points.begin(), points.end());
        vector<vector<int>> hull(2 * n);
        int k = 0;
        for (int i = 0; i < n; ++i) {
            while (k >= 2 && cross(hull[k - 2], hull[k - 1], points[i]) < 0)
                --k;
            hull[k++] = points[i];
        }
        for (int i = n - 2, t = k + 1; i >= 0; --i) {
            while (k >= t && cross(hull[k - 2], hull[k - 1], points[i]) < 0)
                --k;
            hull[k++] = points[i];
        }
        hull.resize(k - 1);
        sort(hull.begin(), hull.end());
        hull.erase(unique(hull.begin(), hull.end()), hull.end());
        return hull;
    }

private:
    int cross(const vector<int>& o, const vector<int>& a,
              const vector<int>& b) {
        return (a[0] - o[0]) * (b[1] - o[1]) - (a[1] - o[1]) * (b[0] - o[0]);
    }
};